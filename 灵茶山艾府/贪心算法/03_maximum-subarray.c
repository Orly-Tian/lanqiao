// 53.最大子数组和
// Created by Administrator on 2025/2/19.
// https://leetcode.cn/problems/maximum-subarray/
// https://www.bilibili.com/video/BV1aY4y1Z7ya

#include <limits.h>


int maxSubArray(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;

	int max = nums[0], result = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (max < 0)
			max = nums[i];
		else
			max += nums[i];

		result = max > result ? max : result;
	}

	return result;
}
