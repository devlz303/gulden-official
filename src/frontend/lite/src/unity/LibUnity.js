import { ipcMain as ipc } from "electron-better-ipc";
import { app } from "electron";
import fs from "fs";
import disk from "asar/lib/disk";
import path from "path";
import store from "@/store";
import libUnity from "native-ext-loader!./lib_unity.node";

// import IpcHandler and SignalHandler mixins
import DefaultIpcHandlersMixin from "./DefaultIpcHandlersMixin";
import DefaultSignalHandlersMixin from "./DefaultSignalHandlersMixin";
import CustomIpcHandlersMixin from "./CustomIpcHandlersMixin";

const isDevelopment = process.env.NODE_ENV !== "production";

class LibUnityBase {
  constructor(options) {
    this.initialized = false;
    this.isTerminated = false;
    this.isCoreReady = false;
    this.isMainWindowReady = false;

    this.options = {
      useTestnet: process.env.UNITY_USE_TESTNET
        ? process.env.UNITY_USE_TESTNET
        : false,
      extraArgs: process.env.UNITY_EXTRA_ARGS
        ? process.env.UNITY_EXTRA_ARGS
        : "",
      ...options
    };

    this.libraryController = new libUnity.NJSILibraryController();
    this.libraryListener = new libUnity.NJSILibraryListener();
    this.walletController = new libUnity.NJSIWalletController();
    this.walletListener = new libUnity.NJSIWalletListener();
    this.accountsController = new libUnity.NJSIAccountsController();
    this.accountsListener = new libUnity.NJSIAccountsListener();
    this.rpcController = new libUnity.NJSIRpcController();

    let buildInfo = this.libraryController.BuildInfo();

    store.dispatch(
      "app/SET_UNITY_VERSION",
      buildInfo.substr(1, buildInfo.indexOf("-") - 1)
    );
  }

  Initialize() {
    if (this.initialized) return;

    this.initialized = true;

    this._registerIpcHandlers();
    this._registerSignalHandlers();
    this._startUnityLib();
  }

  SetMainWindowReady() {
    if (this.isMainWindowReady === true) return; // set core state once
    this.isMainWindowReady = true;
    this._setStateWhenCoreAndMainWindowReady();
  }

  TerminateUnityLib() {
    if (this.libraryController === null || this.isTerminated) return;
    console.log(`terminating unity lib`);
    // TODO:
    // Maybe the call to terminate comes before the core is ready.
    // Then it's better to wait for the coreReady signal and then call TerminateUnityLib
    this.libraryController.TerminateUnityLib();
  }

  _registerIpcHandlers() {
    ipc.answerRenderer("NJSIRpcController.ExecuteAsync", async data => {
      let rpcListener = new libUnity.NJSIRpcListener();

      return new Promise(resolve => {
        rpcListener.onSuccess = (filteredCommand, result) => {
          console.log(`RPC success: ${result}`);
          resolve({
            result: {
              success: true,
              data: result,
              command: filteredCommand
            }
          });
        };

        rpcListener.onError = (filteredCommand, error) => {
          console.error(`RPC error: ${error}`);
          resolve({
            result: {
              success: false,
              data: error,
              command: filteredCommand
            }
          });
        };

        this.rpcController.execute(data.command, rpcListener);
      });
    });

    ipc.on("NJSIRpcController.Execute", (event, command) => {
      let rpcListener = new libUnity.NJSIRpcListener();

      rpcListener.onSuccess = (filteredCommand, result) => {
        console.log(`RPC success: ${result}`);
        event.returnValue = {
          result: {
            success: true,
            data: result,
            command: filteredCommand
          }
        };
      };

      rpcListener.onError = (filteredCommand, error) => {
        console.error(`RPC error: ${error}`);
        event.returnValue = {
          result: {
            success: false,
            data: error,
            command: filteredCommand
          }
        };
      };

      this.rpcController.execute(command, rpcListener);
    });
  }

  _registerSignalHandlers() {
    if (isDevelopment) {
      this.libraryListener.notifyCoreReady = () => {
        console.log(`received: notifyCoreReady`);
      };
      this.libraryListener.logPrint = message => {
        console.log(`unity_core: ${message}`);
      };
      this.libraryListener.notifyBalanceChange = () => {
        console.log(`received: notifyBalanceChange`);
      };
      this.libraryListener.notifyNewMutation = () => {
        console.log(`received: notifyNewMutation`);
      };
      this.libraryListener.notifyUpdatedTransaction = () => {
        console.log(`received: notifyUpdatedTransaction`);
      };
      this.libraryListener.notifyInitWithExistingWallet = () => {
        console.log(`received: notifyInitWithExistingWallet`);
      };
      this.libraryListener.notifyInitWithoutExistingWallet = () => {
        console.log(`received: notifyInitWithoutExistingWallet`);
      };
      this.libraryListener.notifyShutdown = () => {
        console.log(`received: notifyShutdown`);
      };
    }
  }
  _startUnityLib() {
    if (!fs.existsSync(this.options.walletPath)) {
      console.log(`create wallet folder ${this.options.walletPath}`);
      fs.mkdirSync(this.options.walletPath, { recursive: true });
    } else {
      console.log(`wallet folder ${this.options.walletPath} already exists`);
    }

    var staticFilterPath = "";
    var staticFilterOffset = 0;
    var staticFilterLength = 0;
    if (isDevelopment) {
      staticFilterPath = path.join(
        app.getAppPath(),
        "../../../data/staticfiltercp"
      );
    } else {
      staticFilterPath = app.getAppPath();
      if (staticFilterPath.endsWith(".asar")) {
        const filesystem = disk.readFilesystemSync(staticFilterPath);
        const fileInfo = filesystem.getFile("staticfiltercp", true);
        staticFilterOffset =
          parseInt(fileInfo.offset) +
          parseInt(8) +
          parseInt(filesystem.headerSize);
        staticFilterLength = parseInt(fileInfo.size);
      } else {
        staticFilterPath = path.join(staticFilterPath, "staticfiltercp");
      }
    }

    console.log(`init unity lib threaded`);
    this.libraryController.InitUnityLibThreaded(
      this.options.walletPath,
      staticFilterPath,
      staticFilterOffset,
      staticFilterLength,
      this.options.useTestnet,
      true, //spv mode
      this.libraryListener,
      this.options.extraArgs
    );
  }
}

class LibUnity extends DefaultIpcHandlersMixin(
  DefaultSignalHandlersMixin(CustomIpcHandlersMixin(LibUnityBase))
) {}

export default LibUnity;
