// 491.非递减子序列
// Created by Administrator on 2025/3/23.
// https://leetcode.cn/problems/non-decreasing-subsequences/
// https://www.bilibili.com/video/BV1EG4y1h78v

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define resultMax 50000


int *path;
int **result;
int pathTop, resultTop;
int *length;


int max(int *nums, int numsSize) {
	int max = nums[0];
	for (int i = 1; i < numsSize; i++)
		nums[i] = nums[i] > max ? nums[i] : max;
	return max;
}


void backtracking(int *nums, int numsSize, int start) {
	if (pathTop >= 2) {
		// 符合条件的结果深拷贝到result
		int *temp = (int *)malloc(pathTop * sizeof(int));
		for (int i = 0; i < pathTop; i++)
			temp[i] = path[i];
		result[resultTop] = temp;
		length[resultTop++] = pathTop;
	}

	// 数组[0, 200]映射nums[i]的范围[-100, 100]
	int used[201] = {0};

	for (int i = start; i < numsSize; i++) {
		// 维持非递增
		// 若此元素小于当前path的最后一个元素，则跳过此元素
		if (pathTop > 0 && nums[i] < path[pathTop - 1])
			continue;

		// 去重
		// 若此元素在当前层已使用过，则跳过此元素
		if (used[nums[i] + 100])
			continue;

		// 将可以使用的此元素标记已使用
		used[nums[i] + 100] = 1;

		// 入栈
		path[pathTop++] = nums[i];
		// 递归
		backtracking(nums, numsSize, i + 1);
		// 出栈回溯
		pathTop--;
	}
}


int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	// 分配内存并赋初值
    path = (int *)malloc(numsSize * sizeof(int));
	result = (int **)malloc(resultMax * sizeof(int *));
	length = (int *)malloc(resultMax * sizeof(int));
	pathTop = resultTop = 0;

	// 递归函数
	backtracking(nums, numsSize, 0);

	// 为result的长度与内部一维数组长度赋值
	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];
	return result;
}
