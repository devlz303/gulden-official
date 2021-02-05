import Vue from "vue";
import App from "./App.vue";
import store from "./store";
import router from "./router";
import i18n from "./i18n";

import "@/components";

import "@/plugins/fontawesome";

import ToggleButton from "vue-js-toggle-button";
Vue.use(ToggleButton);

import PortalVue from "portal-vue";
Vue.use(PortalVue);

Vue.config.productionTip = false;

new Vue({
  store,
  router,
  i18n,
  render: h => h(App)
}).$mount("#app");
