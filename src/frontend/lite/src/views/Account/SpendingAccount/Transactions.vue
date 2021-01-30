<template>
  <app-content-view v-if="hasMutations">
    <div
      class="mutation-group"
      v-for="group in groupedMutations"
      :key="group.idx"
    >
      <h4>{{ formatDate(group.date) }}</h4>
      <div
        class="mutation-row flex-row"
        v-for="mutation in group.mutations"
        :key="mutation.txHash"
        @click="showTransactionDetails(mutation)"
        :class="mutationRowClass(mutation.txHash)"
      >
        <div class="icon">
          <fa-icon :icon="['fal', mutationIcon(mutation)]" />
        </div>
        <div class="time">{{ formatTime(mutation.timestamp) }}</div>
        <div class="tx-details">
          {{ mutation.recipient_addresses || mutation.txHash }}
        </div>
        <div class="amount">{{ formatAmount(mutation.change) }}</div>
      </div>
    </div>
  </app-content-view>
  <app-content-view v-else>
    <h2>{{ $t("new_wallet.title") }}</h2>
    <p v-html="$t('new_wallet.information')" class="information"></p>
    <template v-slot:buttons-left>
      <button @click="buyGulden" class="buy-gulden">
        {{ $t("buttons.buy_your_first_gulden") }}
      </button>
    </template>
  </app-content-view>
</template>

<script>
import { mapState } from "vuex";
import TransactionDetailsDialog from "../../../components/TransactionDetailsDialog";
import EventBus from "../../../EventBus";

export default {
  name: "Transactions",
  computed: {
    ...mapState("wallet", ["mutations"]),
    hasMutations() {
      return this.mutations ? this.mutations.length > 0 : false;
    },
    groupedMutations() {
      if (this.mutations === null) return [];
      let groupedMutations = [];
      let currentGroup = null;

      for (let i = 0; i < this.mutations.length; i++) {
        let mutation = this.mutations[i];
        let date = new Date(mutation.timestamp * 1000);
        let dateStart = new Date(
          date.getFullYear(),
          date.getMonth(),
          date.getDate()
        );

        if (
          currentGroup === null ||
          currentGroup.date.toString() !== dateStart.toString()
        ) {
          currentGroup = {
            idx: groupedMutations.length,
            date: dateStart,
            mutations: []
          };

          groupedMutations.push(currentGroup);
        }
        currentGroup.mutations.push(mutation);
      }
      return groupedMutations;
    }
  },
  methods: {
    mutationIcon(mutation) {
      switch (mutation.status) {
        case 0: // UNCONFIRMED
          return "hourglass-start";
        case 1: // CONFIRMING
          return "shield";
        case 2: // CONFIRMED
          return "shield-check";
        case 3: // ABANDONED
        case 4: // CONFLICTED
          return "ban";
      }
    },
    formatDate(d) {
      let date = new Date(d);
      let options = {
        year: "numeric",
        month: "long",
        day: "numeric"
      };
      if (date.getFullYear() === new Date().getFullYear()) delete options.year;

      return date.toLocaleString(this.$i18n.locale, options);
    },
    formatTime(timestamp) {
      let date = new Date(timestamp * 1000);
      return `${("0" + date.getHours()).slice(-2)}:${(
        "0" + date.getMinutes()
      ).slice(-2)}`;
    },
    formatAmount(amount) {
      return `${(amount / 100000000).toFixed(2)}`;
    },
    mutationRowClass(txHash) {
      return txHash === this.txHash ? "selected" : "";
    },
    showTransactionDetails(mutation) {
      EventBus.$emit("show-dialog", {
        title: this.$t(
          `transaction_details.title.${
            mutation.change > 0
              ? "incoming_transaction"
              : "outgoing_transaction"
          }`
        ),
        component: TransactionDetailsDialog,
        componentProps: {
          mutation: mutation
        },
        showButtons: false
      });
    },
    buyGulden() {
      window.open("https://gulden.com/#buy", "buy-gulden");
    }
  }
};
</script>

<style lang="less" scoped>
.mutation-group {
  margin-bottom: 30px;
}

h4 {
  margin-bottom: 10px;
}

.mutation-row {
  width: calc(100% + 20px);
  margin: 0 0 0 -10px;
  padding: 5px 10px 5px 10px;
  font-size: 0.95em;
  line-height: 18px;
  cursor: pointer;

  & > .icon {
    flex: 0 0 30px;
  }

  & > .time {
    flex: 0 0 70px;
  }

  & > .tx-details {
    font-size: 0.85em;
  }

  & .amount {
    flex: 1;
    text-align: right;
  }

  &:hover {
    color: var(--primary-color);
    background: #eff3ff;
  }

  &.selected {
    color: #fff;
    background: var(--primary-color);
  }
}

.buy-gulden {
  width: 100%;
}
</style>
