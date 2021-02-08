import { app } from "electron";
import store from "@/store";

let CustomSignalHandlersMixin = superclass =>
  class extends superclass {
    _registerSignalHandlers() {
      if (super._registerSignalHandlers) {
        super._registerSignalHandlers();
      }

      if (!this.libraryListener) {
        throw new Error("LibraryListener does not exist");
      }
      if (!this.libraryController) {
        throw new Error("LibraryController does not exist");
      }

      console.log("Register Custom SignalHandlers");

      let libraryListener = this.libraryListener;
      let libraryController = this.libraryController;

      libraryListener.notifyCoreReady = async () => {
        this._initializeWalletController();
        this._initializeAccountsController();

        this.isCoreReady = true;
        this._setStateWhenCoreAndMainWindowReady();
      };

      libraryListener.notifyBalanceChange = async new_balance => {
        store.dispatch("wallet/SET_BALANCE", new_balance);
      };

      libraryListener.notifyNewMutation = async (/*mutation, self_committed*/) => {
        store.dispatch(
          "wallet/SET_MUTATIONS",
          libraryController.getMutationHistory()
        );
        store.dispatch(
          "wallet/SET_RECEIVE_ADDRESS",
          libraryController.GetReceiveAddress()
        );

        this._updateAccounts();
      };

      libraryListener.notifyUpdatedTransaction = async (/*transaction*/) => {
        store.dispatch(
          "wallet/SET_MUTATIONS",
          libraryController.getMutationHistory()
        );
      };

      libraryListener.notifyInitWithExistingWallet = async () => {
        store.dispatch("app/SET_WALLET_EXISTS", true);
      };

      libraryListener.notifyInitWithoutExistingWallet = async () => {
        this.newRecoveryPhrase = libraryController.GenerateRecoveryMnemonic();
        store.dispatch("app/SET_WALLET_EXISTS", false);
      };

      libraryListener.notifyShutdown = async () => {
        //NB! It is important to set the libraryListener to null here as this is the last thing the core lib is waiting on for clean exit; once we set this to null we are free to quit the app
        libraryListener = null;
        this.isTerminated = true;
        app.quit();
      };

      libraryListener.notifyUnifiedProgress = async progress => {
        console.log(`notifyUnifiedProgress: ${progress}`);
        store.dispatch("app/SET_PROGRESS", progress);
      };
    }

    _setStateWhenCoreAndMainWindowReady() {
      if (super._setStateWhenCoreAndMainWindowReady) {
        super._setStateWhenCoreAndMainWindowReady();
      }

      if (!this.isCoreReady || !this.isMainWindowReady)
        return console.log(
          `isCoreReady: ${this.isCoreReady}, isMainWindowReady: ${this.isMainWindowReady} -> return`
        );

      const balance = this.walletController.GetBalance();
      store.dispatch("wallet/SET_WALLET_BALANCE", balance);

      this._updateAccounts();

      const activeAccount = this.accountsController.getActiveAccount();
      store.dispatch("wallet/SET_ACTIVE_ACCOUNT", activeAccount);

      const receiveAddress = this.libraryController.GetReceiveAddress();
      store.dispatch("wallet/SET_RECEIVE_ADDRESS", receiveAddress);

      const mutations = this.libraryController.getMutationHistory();
      store.dispatch("wallet/SET_MUTATIONS", mutations);

      store.dispatch("app/SET_CORE_READY");
    }

    _initializeWalletController() {
      console.log("_initializeWalletController");

      this.walletListener.notifyBalanceChange = async new_balance => {
        console.log(`walletListener.notifyBalanceChange`);
        store.dispatch("wallet/SET_WALLET_BALANCE", new_balance);
      };

      this.walletListener.notifyNewMutation = async mutation => {
        console.log("walletListener.notifyNewMutation");
        console.log(mutation);
      };

      this.walletListener.notifyUpdatedTransaction = async transaction => {
        console.log("walletListener.notifyUpdatedTransaction");
        console.log(transaction);
      };

      this.walletController.setListener(this.walletListener);
    }

    _initializeAccountsController() {
      console.log("_initializeAccountsController");

      this.accountsListener.onAccountNameChanged = async (
        accountUUID,
        newAccountName
      ) => {
        store.dispatch("wallet/SET_ACCOUNT_NAME", {
          accountUUID,
          newAccountName
        });
      };

      this.accountsListener.onActiveAccountChanged = accountUUID => {
        store.dispatch("wallet/SET_ACTIVE_ACCOUNT", accountUUID);

        store.dispatch(
          "wallet/SET_MUTATIONS",
          this.libraryController.getMutationHistory()
        );

        store.dispatch(
          "wallet/SET_RECEIVE_ADDRESS",
          this.libraryController.GetReceiveAddress()
        );
      };

      this.accountsListener.onAccountAdded = this._updateAccounts;
      this.accountsListener.onAccountDeleted = this._updateAccounts;

      this.accountsController.setListener(this.accountsListener);
    }

    _updateAccounts() {
      const accounts = this.accountsController.listAccounts();
      const accountBalances = this.accountsController.getAllAccountBalances();

      Object.keys(accountBalances).forEach(key => {
        let currentAccount = accounts.find(x => x.UUID === key);
        let currentBalance = accountBalances[key];

        currentAccount.balance = FormatBalance(
          currentBalance.availableIncludingLocked +
            currentBalance.immatureIncludingLocked
        );
        currentAccount.spendable = FormatBalance(
          currentBalance.availableExcludingLocked -
            currentBalance.immatureExcludingLocked
        );
      });

      store.dispatch("wallet/SET_ACCOUNTS", accounts);
    }
  };

const FormatBalance = balance => Math.floor(balance / 1000000) / 100;

export default CustomSignalHandlersMixin;
