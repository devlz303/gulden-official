<template>
  <div id="app">
    <div>routename: {{ routeName }}</div>
    <div>statusses: {{ statusses.join(" > ") }}</div>
    <div>progresses: {{ progresses.join(" > ") }}</div>
    <div>balance: {{ balance }}</div>
    <div>receiveAddress: {{ receiveAddress }}</div>

    <button @click="getRandom">random</button>
    <div>{{ random }}</div>

    <button @click="blockUI">block ui</button>
    <div>{{ ping }}</div>

    <div v-if="mnemonic">
      {{ mnemonic }}
      <button @click="createWallet">create wallet</button>
    </div>
    <div v-else>
      <div>
        <input v-model="command" />
        <button @click="execute">execute</button>
      </div>
      <div>
        <button @click="getProgressAsync">progress</button>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState } from "vuex";
import AppStatus from "@/AppStatus";
import { LibraryController, RpcController } from "@/unity/Controllers";
import { AsyncUtilities } from "@/unity/AsyncUtilities";

let progressTimeout = null;

export default {
  name: "App",
  data() {
    return {
      routeName: null,
      statusses: [],
      mnemonic: null,
      progresses: [],
      random: null,
      ping: null,
      command: null
    };
  },
  created() {
    this.onStatusChanged();
  },
  computed: {
    ...mapState("app", ["status", "progress"]),
    ...mapState("wallet", ["balance", "receiveAddress"]),
    showLoader() {
      return (
        this.splashReady === false ||
        (this.status !== AppStatus.ready && this.status !== AppStatus.setup)
      );
    }
  },
  watch: {
    status() {
      this.onStatusChanged();
    },
    progress() {
      this.progresses.push(this.progress);
    }
  },
  methods: {
    async createWallet() {
      if (
        await LibraryController.InitWalletFromRecoveryPhraseAsync(
          this.mnemonic.phrase,
          "111111"
        )
      ) {
        this.mnemonic = null;
        this.$router.push({ name: "account" });
      }
    },
    async execute() {
      let result = await RpcController.ExecuteAsync(this.command);
      console.log(result);
    },
    async getProgressAsync() {
      console.log(await LibraryController.GetUnifiedProgressAsync());
    },
    async blockUI() {
      this.ping = await AsyncUtilities.BlockUIAsync(Math.random());
    },
    async getRandom() {
      this.random = await AsyncUtilities.GetRandomAsync();
    },
    async onStatusChanged() {
      this.statusses.push(this.status);
      let routeName;
      switch (this.status) {
        case AppStatus.setup:
          routeName = "setup";
          this.mnemonic = await LibraryController.GenerateRecoveryMnemonicAsync();
          break;
        case AppStatus.synchronize:
          routeName = "transactions";
          break;
        case AppStatus.ready:
          routeName = "transactions";
          break;
      }
      this.routeName = routeName;
      this.updateProgress();
    },
    updateProgress() {
      clearTimeout(progressTimeout);
      if (this.progress !== 0 && this.status !== AppStatus.synchronize) return;
      //this.progress = LibraryController.GetUnifiedProgress();
      if (this.progress === 1) {
        this.$store.dispatch("app/SET_STATUS", AppStatus.ready);
      } else {
        progressTimeout = setTimeout(this.updateProgress, 2500);
      }
    }
  }
};
</script>
