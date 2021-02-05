import Vue from "vue";
import App from "./App.vue";
import store from "./store";
import router from "./router";
import i18n from "./i18n";

import "./components";

import VueSlider from "vue-slider-component";
import "vue-slider-component/theme/antd.css";
Vue.component("VueSlider", VueSlider);

import ToggleButton from "vue-js-toggle-button";
Vue.use(ToggleButton);

import PortalVue from "portal-vue";
Vue.use(PortalVue);

import "@/plugins/fontawesome";

Vue.config.productionTip = false;

new Vue({
  store,
  router,
  i18n,
  render: h => h(App)
}).$mount("#app");
