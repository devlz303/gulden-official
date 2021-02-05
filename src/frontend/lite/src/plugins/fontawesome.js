import Vue from "vue";

import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";
import { library } from "@fortawesome/fontawesome-svg-core";
import {
  faAngleDoubleLeft,
  faBan,
  faChevronDown,
  faChevronRight,
  faCog,
  faCopy,
  faEraser,
  faHourglassStart,
  faLock,
  faSearchMinus,
  faSearchPlus,
  faShield,
  faShieldCheck,
  faTimes,
  faUnlock,
  faRedoAlt
} from "@fortawesome/pro-light-svg-icons";

import { faListUl, faLongArrowDown } from "@fortawesome/pro-regular-svg-icons";

import {
  faArrowCircleDown,
  faArrowCircleUp
} from "@fortawesome/free-solid-svg-icons";

library.add([
  faAngleDoubleLeft,
  faArrowCircleDown,
  faArrowCircleUp,
  faBan,
  faChevronDown,
  faChevronRight,
  faCog,
  faCopy,
  faEraser,
  faHourglassStart,
  faListUl,
  faLock,
  faLongArrowDown,
  faSearchMinus,
  faSearchPlus,
  faShield,
  faShieldCheck,
  faTimes,
  faUnlock,
  faRedoAlt
]);

Vue.component("fa-icon", FontAwesomeIcon);
