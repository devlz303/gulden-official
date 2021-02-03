<template>
  <div class="price-view">
    <div class="chart-container">
      <line-chart
        :chart-data="chartData"
        :options="options"
        class="chart"
      ></line-chart>
    </div>
  </div>
</template>

<script>
import LineChart from "@/components/charts/lineChart";

import CoinGecko from "coingecko-api";
const CoinGeckoClient = new CoinGecko();

let timeout = null;

export default {
  components: {
    LineChart
  },
  data() {
    return {
      prices: [],
      options: {
        maintainAspectRatio: false,
        aspectRatio: 1,
        legend: {
          display: false
        },
        layout: {},
        scales: {
          xAxes: [
            {
              type: "time",
              time: {
                displayFormats: {
                  millisecond: "HH:mm",
                  second: "HH:mm",
                  minute: "HH:mm",
                  hour: "HH:mm",
                  day: "HH:mm",
                  week: "HH:mm",
                  month: "HH:mm",
                  quarter: "HH:mm",
                  year: "HH:mm"
                }
              },
              gridLines: {
                display: false
              }
            }
          ],
          yAxes: [
            {
              gridLines: {
                display: false
              }
            }
          ]
        }
      }
    };
  },
  created() {
    this.updateChart();
  },
  beforeDestroy() {
    clearTimeout(timeout);
  },
  computed: {
    chartData() {
      return {
        datasets: [
          {
            data: this.computedPrices,
            backgroundColor: "transparent",
            borderColor: "#ee6622",
            borderWidth: 1,
            pointRadius: 0
          }
        ]
      };
    },
    computedPrices() {
      return this.prices.map(o => {
        return { x: new Date(o[0]), y: o[1] };
      });
    }
  },
  methods: {
    async updateChart() {
      try {
        clearTimeout(timeout);

        console.log("update data");

        let dtFrom = new Date();
        dtFrom = dtFrom.setDate(dtFrom.getDate() - 1);
        let dtTo = new Date();

        const response = await CoinGeckoClient.coins.fetchMarketChartRange(
          "gulden",
          {
            from: this.toUnixTimestamp(dtFrom),
            to: this.toUnixTimestamp(dtTo)
          }
        );

        if (response.success === true) {
          this.prices = response.data.prices;
        }
      } finally {
        timeout = setTimeout(this.updateChart, 60 * 1000);
      }
    },
    toUnixTimestamp(date) {
      return Math.round(new Date(date).getTime() / 1000);
    }
  }
};
</script>

<style lang="less" scoped></style>
