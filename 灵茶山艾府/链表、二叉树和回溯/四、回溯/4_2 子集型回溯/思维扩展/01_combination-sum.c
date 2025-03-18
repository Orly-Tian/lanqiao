// 39.组合总和
// Created by Administrator on 2025/3/18.
// https://leetcode.cn/problems/combination-sum/
// https://www.bilibili.com/video/BV1KT4y1M7HJ

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>


// path为符合条件的组合数，result保存所有符合条件的组合数
int *path;
int **result;
// 栈顶指针
int pathTop, resultTop;
// 组合数的和
long pathSum;
// 记录每个符合条件的组合的长度
int *length;


void backtrackting(int *candidates, int candidatesSize, int target, int start) {
	// 若pathSum大于等于target则应停止继续递归
	if (pathSum >= target) {
		// 若组合数符合条件
		if (pathSum == target) {
			// 深拷贝至result
			int *temp = (int *)malloc(25 * sizeof(int));
			for (int i = 0; i < pathTop; i++)
				temp[i] = path[i];
			result[resultTop] = temp;
			// 将此组合数的长度保存
			length[resultTop++] = pathTop;
		}
		return;
	}

	// 从start开始遍历到元素组末尾
	for (int i = start; i < candidatesSize; i++) {
		// 将遍历到的值累加到pathSum，且保存至path
		pathSum += candidates[i];
		path[pathTop++] = candidates[i];
		// 递归函数，且每个元素可以取多次值，所以start传入当前遍历索引
		backtrackting(candidates, candidatesSize, target, i);
		// 回溯，元素出栈
		pathSum -= candidates[i];
		pathTop--;
	}
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	// 分配内存且赋初值
    path = (int *)malloc(25 * sizeof(int));
	result = (int **)malloc(155 * sizeof(int *));
	length = (int *)malloc(155 * sizeof(int));
	pathSum = pathTop = resultTop = 0;

	backtrackting(candidates, candidatesSize, target, 0);

	// 指定二维数组长度
	*returnSize = resultTop;
	// 通过数组returnColumnSize指定二维数组内各一维数组长度
	*returnColumnSizes = (int *)malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = length[i];

	// 返回结果
	return result;
}

