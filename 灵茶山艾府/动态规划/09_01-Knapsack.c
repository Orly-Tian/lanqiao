// 01背包
// Created by Administrator on 2025/3/5.
// 代码随想录：https://www.bilibili.com/video/BV1cg411g7Y6
// 动画图解：https://www.bilibili.com/video/BV1pY4y1J7na

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	// 物品数量与背包容量
	int n, bagweight;
	scanf("%d %d", &n, &bagweight);

	// 各物品的重量与价值
	int *weight = (int *)malloc(n * sizeof(int));
	int *value = (int *)malloc(n * sizeof(int));
	for (int i = 0 ; i < n; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);

	// 创建DP
	int **dp = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		dp[i] = (int *)malloc((bagweight + 1) * sizeof(int));
		for (int j = 0; j <= bagweight; j++)
			dp[i][j] = 0;
	}

	// 遍历第0行，即第一个物品
	// 若背包容量大于第一个物品的重量时，此时最大价值为第一个物品的价值
	for (int j = weight[0]; j <= bagweight; j++)
		dp[0][j] = value[0];

	// 遍历物品
	for (int i = 1; i < n; i++) {
		// 遍历背包
		for (int j = 0; j <= bagweight; j++) {
			if (j < weight[i])
				// 若当前背包容量小于该物品质量，则当前最大价值为dp[i - 1][j]
				dp[i][j] = dp[i - 1][j];
			else
				// 否则，取dp[i - 1][j]与dp[i - 1][j - weight[i]] + value[i]的最大值
				// 即，取(不放此物品,继承上一个物品位置的最大价值)与(放此物品+腾开此物品空间剩余空间的最大价值)的最大值
				dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	// 输出最后一个坐标的值
	printf("%d\n", dp[n - 1][bagweight]);

	// 释放内存
	for (int i = 0; i < n; i++)
		free(dp[i]);
	free(dp);
	free(weight);
	free(value);

	return 0;
}

