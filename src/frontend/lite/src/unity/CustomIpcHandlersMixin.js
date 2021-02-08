import { ipcMain as ipc } from "electron-better-ipc";
import axios from "axios";
import FormData from "form-data";
import store from "@/store";

let CustomIpcHandlersMixin = superclass =>
  class extends superclass {
    _registerIpcHandlers() {
      if (super._registerIpcHandlers) {
        super._registerIpcHandlers();
      }
      if (!this.libraryController) {
        throw new Error("LibraryController does not exist");
      }

      console.log("Register Custom IpcHandlers");

      ipc.answerRenderer("BackendUtilities.GetBuySessionUrl", async () => {
        console.log(`IPC: BackendUtilities.GetBuySessionUrl()`);
        try {
          var formData = new FormData();
          formData.append("address", store.state.wallet.receiveAddress);
          formData.append("currency", "gulden");
          formData.append("uuid", this.walletController.GetUUID());

          let response = await axios.post(
            "https://www.blockhut.com/buysession.php",
            formData,
            {
              headers: formData.getHeaders()
            }
          );

          event.returnValue = {
            success: response.data.status_message === "OK",
            result: `https://blockhut.com/buy.php?sessionid=${response.data.sessionid}`
          };
        } catch (e) {
          console.error(e);
          return {
            error: e,
            result: null
          };
        }
      });

      ipc.answerRenderer("AsyncUtilities.GetRandomAsync", async () => {
        console.log(`IPC: BackendUtilities.GetRandomAsync()`);
        return {
          success: true,
          result: Math.random()
        };
      });

      ipc.answerRenderer("AsyncUtilities.BlockUIAsync", async () => {
        console.log(`IPC: BackendUtilities.BlockUIAsync()`);
        await new Promise(r => setTimeout(r, 5000));
        return {
          success: true,
          result: new Date()
        };
      });

      ipc.on("AsyncUtilities.BlockUI", async event => {
        console.log(`IPC: AsyncUtilities.BlockUI()`);
        await new Promise(r => setTimeout(r, 5000));
        event.returnValue = {
          success: true,
          result: new Date()
        };
      });
    }
  };

export default CustomIpcHandlersMixin;
