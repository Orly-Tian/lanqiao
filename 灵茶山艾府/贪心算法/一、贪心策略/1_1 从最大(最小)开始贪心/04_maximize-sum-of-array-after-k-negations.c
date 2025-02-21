// 1005.K次取反后最大化的数组和
// Created by Administrator on 2025/2/21.
// https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
// https://www.bilibili.com/video/BV1fD4y117gp

#include <stdlib.h>


int cmp(const void *a, const void *b) {
	// 按绝对值从大到小排列
	return abs(*(int *)b) - abs(*(int *)a);
}


int largestSumAfterKNegations(int* nums, int numsSize, int k) {
	qsort(nums, numsSize, sizeof(int), cmp);

	for (int i = 0; i < numsSize; i++) {
		// 将绝对值最大的负数取反
		if (nums[i] < 0 && k > 0) {
			nums[i] *= -1;
			k--;
		}
	}

	// 若仍有k，则将绝对值最小的数(即numsSize - 1)取反
	if (k % 2 != 0)
		nums[numsSize - 1] *= -1;

	int result = 0;
	for (int i = 0; i < numsSize; i++)
		result += nums[i];

	return result;
}

