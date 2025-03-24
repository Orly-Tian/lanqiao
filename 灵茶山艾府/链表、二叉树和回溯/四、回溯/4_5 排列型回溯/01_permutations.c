// 46.全排列
// Created by Administrator on 2025/3/24.
// https://leetcode.cn/problems/permutations/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define resultMax 20000


int *path;
int **result;
int pathTop, resultTop;
int *length;


void backtracking(int *nums, int numsSize, int *used) {
	// 若path长度等于数组长度，则符合全排列条件
	if (pathTop == numsSize) {
		// 深拷贝至结果
		int *temp = (int *)malloc(pathTop * sizeof(int));
		for (int i = 0; i < pathTop; i++)
			temp[i] = path[i];
		result[resultTop] = temp;
		length[resultTop++] = pathTop;
		return;
	}

	// 从0开始遍历nums数组
	for (int i = 0; i < numsSize; i++) {
		// 树枝去重，避免在单个结果中取到重复值
		if (used[nums[i] + 10])
			continue;
		// 标记此元素已使用
		used[nums[i] + 10] = 1;
		// 入栈
		path[pathTop++] = nums[i];
		// 递归
		backtracking(nums, numsSize, used);
		// 回溯出栈，且重新将此元素标记为未使用
		used[nums[i] + 10] = 0;
		pathTop--;
	}
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int *)malloc((numsSize + 1) * sizeof(int));
	result = (int **)malloc(resultMax * sizeof(int *));
	length = (int *)malloc(resultMax * sizeof(int));
	pathTop = resultTop = 0;

	// 数组[0, 20]映射nums[i]范围[-10, 10]
	int used[21] = {0};

	// 树枝去重，将used数组通过参数传递
	backtracking(nums, numsSize, used);

	*returnSize = resultTop;
	(*returnColumnSizes) = malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];
	return result;
}
