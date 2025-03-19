// 40.组合总和2
// Created by Administrator on 2025/3/19.
// https://leetcode.cn/problems/combination-sum-ii/
// https://www.bilibili.com/video/BV12V4y1V73A

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


int *path;
int **result;
int pathTop, resultTop;
int pathSum;
int *length;


int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


void backtracking(int *candidates, int candidatesSize, int target, int start) {
	// 若组合数和大于等于target，则无论是否符合条件都应停止递归
	if (pathSum >= target) {
		// 若符合条件
		if (pathSum == target) {
			// 深拷贝至结果
			int *temp = (int *)malloc(pathTop * sizeof(int));
			for (int i = 0; i < pathTop; i++)
				temp[i] = path[i];
			result[resultTop] = temp;
			length[resultTop++] = pathTop;
		}
		return;
	}

	// 单层递归，遍历start到原素组末尾的元素
	for (int i = start; i < candidatesSize; i++) {
		// 若同一层树中的元素相等则跳过
		if (i > start && candidates[i] == candidates[i - 1])
			continue;
		// 元素入栈
		pathSum += candidates[i];
		path[pathTop++] = candidates[i];
		// 递归函数，start后移一位
		backtracking(candidates, candidatesSize, target, i + 1);
		// 回溯，元素出栈
		pathSum -= candidates[i];
		pathTop--;
	}

}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	// 原数组排序
	qsort(candidates, candidatesSize, sizeof(int), cmp);

	// 分配内存并赋初值
    path = (int *)malloc(50 * sizeof(int));
	result = (int **)malloc(100 * sizeof(int **));
	length = (int *)malloc(100 * sizeof(int));
	pathTop = resultTop = 0;

	backtracking(candidates, candidatesSize, target, 0);

	// 为返回的二维数组指针与一维数组指针赋值
	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];
	return result;
}

