class MaxProfitWithFee {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        if (n <= 1) return 0;

        int buy = -prices[0];
        int sell = 0;

        for (int i = 1; i < n; i++) {
            int prevBuy = buy;
            buy = Math.max(buy, sell - prices[i]);
            sell = Math.max(sell, prevBuy + prices[i] - fee);
        }

        return sell;
    }
}
