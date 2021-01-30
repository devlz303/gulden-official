<template>
  <div class="app-content-view">
    <div class="content">
      <slot />
    </div>
    <div class="buttons">
      <div class="left">
        <slot name="buttons-left" />
      </div>
      <div class="buttons-right">
        <slot name="buttons-right" />
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "AppContentView"
};
</script>

<style lang="less" scoped>
.app-content-view {
  height: 100%;
  display: flex;
  flex-direction: column;
}
.content {
  flex: 1;
}
.buttons {
  display: flex;
  flex-direction: row;

  & > .left {
    flex: 1;
  }
}
</style>
