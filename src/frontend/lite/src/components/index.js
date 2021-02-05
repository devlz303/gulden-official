import Vue from "vue";

import AppContentView from "./layout/AppContentView";
import ClipboardField from "./ClipboardField";
import FontAwesomeIcon from "./FontAwesomeIcon";
import GuldenFormField from "./layout/GuldenFormField";
import GuldenSection from "./layout/GuldenSection";

Vue.component(AppContentView.name, AppContentView);
Vue.component(ClipboardField.name, ClipboardField);
Vue.component("fa-icon", FontAwesomeIcon);
Vue.component(GuldenFormField.name, GuldenFormField);
Vue.component(GuldenSection.name, GuldenSection);
