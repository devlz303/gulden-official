import Vue from "vue";
import Vuex from "vuex";
import { createPersistedState, createSharedMutations } from "vuex-electron";
import Store from "electron-store";
import syncState from "./syncState";
import modules from "./modules";
import walletPath from "@/walletPath";

Vue.use(Vuex);

let userSettingsPersistedState = () => {};
// create persistate state in main process only
if (process.type !== "renderer") {
  // use user-settings.json file to store settings in wallet folder
  let store = new Store({ cwd: walletPath, name: "user-settings" });

  userSettingsPersistedState = createPersistedState({
    storage: store,
    invertIgnored: true, // use invertIgnored because we only want to store the paths in the ignoredPaths list
    ignoredPaths: ["app.theme"]
  });
}
export default new Vuex.Store({
  modules: modules,
  plugins: [syncState, userSettingsPersistedState, createSharedMutations()]
});
