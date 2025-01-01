// 1.两数之和
// Created by Administrator on 2025/1/1.
// https://leetcode.cn/problems/two-sum/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	for (int i = 0; i < numsSize; i++) {
		for (int j = i+1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				*returnSize = 2;
				int *result = malloc(2 * sizeof(int));
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}
