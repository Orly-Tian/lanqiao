// 77.组合
// Created by Administrator on 2025/2/21.
// https://leetcode.cn/problems/combinations/
// https://www.bilibili.com/video/BV1ti4y1L7cv

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


// 一维数组栈，存放组合数结果
int *path, pathTop;
// 二维数组栈，存放所有的组合数结果
int **result, resultTop;


// n为题目范围
// k为组合数长度
// start为当前递归的位置，即下一层递归的开始索引
void backtrackting(int n, int k, int start) {
	// 若路径长度等于组合数的长度，则已经到达叶子节点，即找到了目标组合数
	if (pathTop == k) {
		// 将当前组合数加入到result
		int *temp = (int *)malloc(k * sizeof(int));
		for (int i = 0; i < k; i++)
			temp[i] = path[i];
		result[resultTop++] = temp;
		return;
	}
	// 单层递归逻辑：从start遍历到原数组末尾
	for (int j = start; j <= n - (k - pathTop) + 1; j++) {
		// 添加元素至栈
		path[pathTop++] = j;
		// 递归函数，start值后移一位
		backtrackting(n, k, j + 1);
		// 回溯，元素出栈
		pathTop--;
	}
}


int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
	// path为树的路径，即用数组存放组合结果
    path = (int *)malloc(k * sizeof(int));
	// result为所有组合的二维数组
	result = (int **)malloc(10000 * sizeof(int *));
	pathTop = resultTop = 0;

	backtrackting(n, k, 1);
	
	// 二维数组长度为resultTop的值
	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
	// 将二维数组中的所有一维数组长度赋值为k
	for (int i = 0; i < *returnSize; i++)
		(*returnColumnSizes)[i] = k;

	return result;
}

