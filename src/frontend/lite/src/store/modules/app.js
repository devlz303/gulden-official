import { Menu } from "electron";
import AppStatus from "@/AppStatus";

function EnableDebugWindowOnCoreReady() {
  try {
    let menu = Menu.getApplicationMenu();
    if (menu === null) return;
    menu.items
      .find(x => x.label === "Help")
      .submenu.items.find(x => x.label === "Debug window").enabled = true;
  } catch (e) {
    console.error(e);
  }
}

const app = {
  namespaced: true,
  state: {
    coreReady: false,
    language: null,
    progress: null,
    rate: null,
    splashReady: false,
    status: AppStatus.start,
    theme: null,
    unityVersion: null,
    walletExists: null,
    walletVersion: null
  },
  mutations: {
    SET_CORE_READY(state) {
      state.coreReady = true;
    },
    SET_LANGUAGE(state, language) {
      state.language = language;
    },
    SET_PROGRESS(state, progress) {
      state.progress = progress;
    },
    SET_RATE(state, rate) {
      state.rate = rate;
    },
    SET_SPLASH_READY(state) {
      state.splashReady = true;
    },
    SET_STATUS(state, status) {
      if (state.status === AppStatus.shutdown) return; // shutdown in progress, do not switch to other status
      state.status = status;
    },
    SET_THEME(state, theme) {
      state.theme = theme;
    },
    SET_UNITY_VERSION(state, version) {
      state.unityVersion = version;
    },
    SET_WALLET_EXISTS(state, walletExists) {
      state.walletExists = walletExists;
    },
    SET_WALLET_VERSION(state, version) {
      state.walletVersion = version;
    }
  },
  actions: {
    SET_CORE_READY({ commit, state }) {
      commit(
        "SET_STATUS",
        state.progress === 1 ? AppStatus.ready : AppStatus.synchronize
      );
      commit("SET_CORE_READY");
      EnableDebugWindowOnCoreReady();
    },
    SET_LANGUAGE({ commit }, language) {
      commit("SET_LANGUAGE", language);
    },
    SET_PROGRESS({ commit }, progress) {
      commit("SET_PROGRESS", progress);
    },
    SET_RATE({ commit }, rate) {
      commit("SET_RATE", rate);
    },
    SET_SPLASH_READY({ commit }) {
      commit("SET_SPLASH_READY");
    },
    SET_STATUS({ commit }, status) {
      commit("SET_STATUS", status);
    },
    SET_THEME({ commit }, theme) {
      commit("SET_THEME", theme);
    },
    SET_UNITY_VERSION({ commit }, version) {
      commit("SET_UNITY_VERSION", version);
    },
    SET_WALLET_EXISTS({ commit }, walletExists) {
      let status = walletExists ? AppStatus.synchronize : AppStatus.setup;
      commit("SET_STATUS", status);
      commit("SET_WALLET_EXISTS", walletExists);
    },
    SET_WALLET_VERSION({ commit }, version) {
      commit("SET_WALLET_VERSION", version);
    }
  }
};

export default app;
