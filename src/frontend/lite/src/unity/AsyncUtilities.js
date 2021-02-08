import { ipcRenderer as ipc } from "electron-better-ipc";

class AsyncUtilities {
  static async GetRandomAsync() {
    return handleError(await ipc.callMain("AsyncUtilities.GetRandomAsync"));
  }

  static async BlockUIAsync() {
    return handleError(await ipc.callMain("AsyncUtilities.BlockUIAsync"));
  }

  static async BlockUI() {
    return handleError(ipc.sendSync("AsyncUtilities.BlockUI"));
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
