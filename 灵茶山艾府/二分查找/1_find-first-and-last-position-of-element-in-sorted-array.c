// 34.在排序数组中查找元素的第一个和最后一个位置
// Created by Administrator on 2024/12/6.
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


// 闭区间
int lowerBound(int *nums, int numsSize, int target) {
	// 闭区间 [left, right]
    int left = 0, right = numsSize - 1;

	// 区间不为空
	while (left <= right) {
		int mid = left +  (right - left) / 2;

		// 二分查找
		if (nums[mid] >= target)
			// 范围缩小到 [left, mid-1]
			right = mid - 1;
		else
			// 范围缩小到 [mid+1, right]
			left = mid + 1;
	}

	return left;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *result = malloc(2 * sizeof(int));
	*returnSize = 2;

	int start = lowerBound(nums, numsSize, target);
	// 若nums中未找到target值
	if (start == numsSize || nums[start] != target) {
		result[0] = -1;
		result[1] = -1;
		return result;
	}

	// 找到target+1的值在nums数组中的位置-1,也就是target的最后一个值的位置
	// start存在,则end必定存在
	int end = lowerBound(nums, numsSize, target + 1) - 1;
	result[0] = start;
	result[1] = end;

	return result;
}


/*	leetcode灵茶山艾府题解:
 *		(二分查找,时间复杂度O(log n))
 *		https://www.bilibili.com/video/BV1AP41137w7/?vd_source=4c293aa27f67a76d01553a3b9517eaf3
 *
 */

