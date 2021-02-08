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

    <input v-model="command" />
    <button @click="execute">execute</button>
    <button @click="getProgressAsync">progress</button>
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
      progress: 0,
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
    ...mapState("app", ["status"]),
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
    async execute() {
      let result = await RpcController.ExecuteAsync(this.command);
      console.log(result);
    },
    async getProgressAsync() {
      console.log(await LibraryController.GetUnifiedProgressAsync());
    },
    async blockUI() {
      this.ping = await AsyncUtilities.BlockUI(Math.random());
    },
    async getRandom() {
      this.random = await AsyncUtilities.GetRandom();
    },
    onStatusChanged() {
      this.statusses.push(this.status);
      let routeName;
      switch (this.status) {
        case AppStatus.setup:
          routeName = "setup";
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
      this.progress = LibraryController.GetUnifiedProgress();
      if (this.progress === 1) {
        this.$store.dispatch("app/SET_STATUS", AppStatus.ready);
      } else {
        progressTimeout = setTimeout(this.updateProgress, 2500);
      }
    }
  }
};
</script>
