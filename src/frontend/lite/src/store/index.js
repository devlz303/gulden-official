import Vue from "vue";
import Vuex, { createLogger } from "vuex";
import { createPersistedState, createSharedMutations } from "vuex-electron";
import Store from "electron-store";
import syncState from "./syncState";
import modules from "./modules";
import walletPath from "@/walletPath";

Vue.use(Vuex);

const plugins = [syncState, createSharedMutations()];

const isDevelopment = process.env.NODE_ENV !== "production";
// add vuex logger when debugging and only in renderer
if (isDevelopment && process.type === "renderer") {
  plugins.push(createLogger());
}

// add persistate state in main process only
if (process.type !== "renderer") {
  plugins.push(
    createPersistedState({
      storage: new Store({ cwd: walletPath, name: "user-settings" }), // use user-settings.json file to store settings in wallet folder
      invertIgnored: true, // use invertIgnored because we only want to store the paths in the ignoredPaths list
      ignoredPaths: ["app.theme"] // <-- these properies will be stored in user-settings.json
    })
  );
}

export default new Vuex.Store({
  modules: modules,
  plugins: plugins
});
