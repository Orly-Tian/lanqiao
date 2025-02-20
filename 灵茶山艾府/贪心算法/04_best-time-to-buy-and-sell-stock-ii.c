// 122.买卖股票的最佳时机2
// Created by Administrator on 2025/2/20.
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
// https://www.bilibili.com/video/BV1ev4y1C7na


int maxProfit(int* prices, int pricesSize) {
	if (pricesSize == 0)
		return 0;

	int result = 0;
	for (int i = 0; i < pricesSize - 1; i++) {
		int curPrice = prices[i + 1] - prices[i];
		if (curPrice > 0)
			result += curPrice;
	}

	return result;
}
