import { ipcRenderer as ipc } from "electron-better-ipc";

class AsyncUtilities {
  static async GetRandom() {
    return handleError(await ipc.callMain("AsyncUtilities.GetRandom"));
  }

  static async BlockUI() {
    return handleError(await ipc.callMain("AsyncUtilities.BlockUI"));
  }
}

export { AsyncUtilities };

function handleError(response) {
  if (response.error) {
    // todo: maybe keep a list of notifications which can be shown
    console.error(response.error);
    return null;
  }
  return response.result;
}
