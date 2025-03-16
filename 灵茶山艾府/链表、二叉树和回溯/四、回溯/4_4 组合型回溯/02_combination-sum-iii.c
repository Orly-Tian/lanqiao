// 216.组合总和3
// Created by Administrator on 2025/3/16.
// https://leetcode.cn/problems/combination-sum-iii/
// https://www.bilibili.com/video/BV1wg411873x

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


// path一维数组保存当前组合数
int *path;
// result二维数组保存所有组合数结果
int **result;
int pathTop, resultTop;


// k为组合数长度
// targetSum为目标的组合数总和
// sum为当前组合数和
// start为当前递归位置，即下一层递归开始的索引
void backtracking(int k, int targetSum, int sum, int start) {
	// 若path的长度等于目标组合数的长度，则不再向下递归
	if (pathTop == k) {
		// 当前组合数总和等于目标总和
		if (sum == targetSum) {
			// 将结果通过深拷贝将结果保存至result
			int *temp = (int *)malloc(k * sizeof(int));
			for (int i = 0; i < pathTop; i++)
				temp[i] = path[i];
			result[resultTop++] = temp;
		}
		// 若path长度等于目标组合数长度，不管结果是否为目标值都停止继续递归
		return;
	}

	// 遍历1-9
	for (int i = start; i <= 9; i++) {
		// 当前和+=i，且此值入path栈
		sum += i;
		path[pathTop++] = i;
		// 递归函数，且start后移一位
		backtracking(k, targetSum, sum, i + 1);
		// 回溯，元素出栈
		sum -= i;
		pathTop--;
	}

}


int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
	// 分配内存空间并初始化栈
	path = (int *)malloc(k * sizeof(int));
	result = (int **)malloc(20 * sizeof(int *));
	pathTop = resultTop = 0;

	backtracking(k, n, 0, 1);

	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++) {
		(*returnColumnSizes)[i] = k;
	}

	return result;
}

