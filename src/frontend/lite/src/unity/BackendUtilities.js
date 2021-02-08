import { ipcRenderer as ipc } from "electron-better-ipc";

class BackendUtilities {
  static async GetBuySessionUrl() {
    return handleError(ipc.callMain("BackendUtilities.GetBuySessionUrl"));
  }
}

export { BackendUtilities };

function handleError(response) {
  if (response.error) {
    // todo: maybe keep a list of notifications which can be shown
    console.error(response.error);
    return null;
  }
  return response.result;
}
