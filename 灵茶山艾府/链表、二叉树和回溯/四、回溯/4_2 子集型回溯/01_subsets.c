// 78.子集
// Created by Administrator on 2025/3/21.
// https://leetcode.cn/problems/subsets/
// https://www.bilibili.com/video/BV1U84y1q7Ci

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define resultMAX 10000


int *path;
int **result;
int pathTop, resultTop;
int *length;


void backtracking(int *nums, int numsSize, int k, int start) {
	if (pathTop == k) {
		int *temp = (int *)malloc(k * sizeof(int));
		for (int i = 0; i < k; i++)
			temp[i] = path[i];
		result[resultTop] = temp;
		length[resultTop++] = pathTop;
	}

	for (int i = start; i < numsSize; i++) {
		path[pathTop++] = nums[i];
		backtracking(nums, numsSize, k, i + 1);
		pathTop--;
	}
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int *)malloc(15 * sizeof(int));
	result = (int **)malloc(resultMAX * sizeof(int *));
	length = (int *)malloc(resultMAX * sizeof(int));
	pathTop = resultTop = 0;

	// 先单独加入空集
	result[resultTop] = (int *)malloc(sizeof(int));
	length[resultTop++] = 0;

	for (int i = 1; i <= numsSize; i++) {
		backtracking(nums, numsSize, i, 0);
	}

	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc(resultMAX * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];
	return result;
}

