import Vue from "vue";
import App from "@/App.vue";
import store from "@/store";
import router from "@/router";

import "@/components";

import "@/plugins/fontawesome";
import i18n from "@/plugins/i18n";

Vue.config.productionTip = false;

new Vue({
  store,
  router,
  i18n,
  render: h => h(App)
}).$mount("#app");
