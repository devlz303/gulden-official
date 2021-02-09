<template>
  <div class="app-content-view">
    <div class="content">
      <slot />
    </div>
    <div class="footer">
      <div class="footer-left">
        <slot name="footer-left" />
      </div>
      <div class="footer-right">
        <slot name="footer-right" />
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "AppContentView",
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
.footer {
  display: flex;
  flex-direction: row;

  & > .footer-left {
    flex: 1;
  }
}
</style>
