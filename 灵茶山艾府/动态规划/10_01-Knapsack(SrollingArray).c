// 动态规划DP：01背包(滚动数组优化)
// Created by Administrator on 2025/3/10.
// https://www.bilibili.com/video/BV1BU4y177kY

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	// 物品数量与背包容量
	int n, bagweight;
	scanf("%d %d", &n, &bagweight);

	// 物品的重量与价值
	int *weight = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	int *value = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);

	// 定义dp数组，dp[j]表示为背包在容量为j的情况下所能装的最大价值
	int *dp = (int *)malloc((bagweight + 1) * sizeof(int));
	// 初始化dp
	for (int j = 0; j <= bagweight; j++)
		dp[j] = 0;

	// 遍历物品
	for (int i = 0; i < n; i++) {
		// 倒序遍历背包容量，为了防止同一物品被多次添加
		for (int j = bagweight; j >= weight[i]; j--)
			// 取 未放物品dp[j] 与 放此物品dp[j - weight[i] + value[i]] 的最大值
			dp[j] = fmax(dp[j], dp[j - weight[i]] + value[i]);
	}

	// 输出最大价值
	printf("%d", dp[bagweight]);

	// 释放内存，防止内存泄露
	free(weight);
	free(value);
	free(dp);

	return 0;
}

