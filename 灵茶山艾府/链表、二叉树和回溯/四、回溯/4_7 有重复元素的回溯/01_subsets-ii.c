// 90.子集2
// Created by Administrator on 2025/3/22.
// https://leetcode.cn/problems/subsets-ii/
// https://www.bilibili.com/video/BV1vm4y1F71J

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define resultMax 10000


int *path;
int **result;
int pathTop, resultTop;
int *length;


int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


void backtracking(int *nums, int numsSize, int k, int start) {
	if (pathTop == k) {
		int *temp = (int *)malloc(pathTop * sizeof(int));
		for (int i = 0; i < pathTop; i++)
			temp[i] = path[i];
		result[resultTop] = temp;
		length[resultTop++] = pathTop;
		return;
	}

	for (int i = start; i < numsSize; i++) {
		// (已排序)同一层遇到相同元素则跳过
		if (i > start && nums[i] == nums[i - 1])
			continue;
		path[pathTop++] = nums[i];
		backtracking(nums, numsSize, k, i + 1);
		pathTop--;
	}
}


int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);

	// 分配内存并赋初值
    path = (int *)malloc(10 * sizeof(int));
	result = (int **)malloc(resultMax * sizeof(int *));
	length = (int *)malloc(resultMax * sizeof(int *));
	pathTop = resultTop = 0;

	// 手动保存空集至第一个result
	result[resultTop] = (int *)malloc(sizeof(int));
	length[resultTop++] = 0;

	for (int i = 1; i <= numsSize; i++)
		backtracking(nums, numsSize, i, 0);

	*returnSize = resultTop;
	*returnColumnSizes = malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];
	return result;
}

