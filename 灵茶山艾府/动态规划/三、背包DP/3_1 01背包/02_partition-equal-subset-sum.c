// 416.分隔等和子集
// Created by Administrator on 2025/3/12.
// https://leetcode.cn/problems/partition-equal-subset-sum/
// https://www.bilibili.com/video/BV1rt4y1N7jE

#include <math.h>
#include <stdbool.h>


// 看作物品重量与价值相等的01背包问题
// 基于一维滚动数组实现
bool canPartition(int* nums, int numsSize) {
	int total = 0;
	for (int i = 0; i < numsSize; i++)
		total += nums[i];

	// 若数组和是奇数，则不可能满足条件
	if (total % 2 == 1) return false;
	int target = total / 2;

	// 定义dp数组，dp[j]表示背包容量为j时能装物品的最大价值
	// 题目范围：数组元素不超过100，数组大小不超过200
	// 即数组和不超过20000，则dp数组长度不超过10001
	int dp[10001];

	// 遍历物品
	for (int i = 0; i < numsSize; i++) {
		// 遍历背包，条件为背包容量大于此时物品重量
		for (int j = target; j >= nums[i]; j--) {
			dp[j] = fmax(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}

	// 若装入物品重量等于目标值(数组和的一半)
	if (dp[target] == target)
		return true;
	return false;
}

