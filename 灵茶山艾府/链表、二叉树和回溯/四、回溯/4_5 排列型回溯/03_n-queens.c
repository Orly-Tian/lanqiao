// 51.N皇后(未完成)
// Created by Administrator on 2025/3/26.
// https://leetcode.cn/problems/n-queens/
// https://www.bilibili.com/video/BV1Rd4y1c7Bq

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
 *	未完成
 */

#include <stdlib.h>

#define resultMax 1


char **path;
char ***result;
int pathTop, resultTop;


int isValid(int row, int col, int n) {
	// 检查同一行或同一列是否有皇后
	for (int i = 0; i < n; i++)
		if (path[row][i] == 'Q' || path[i][col] == 'Q')
			return 0;

	// 检查斜角45度是否有皇后
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (path[i][j] == 'Q')
			return 0;
	// 检查斜角135度是否有皇后
	for (int i = row - 1, j = row + 1; i >= 0 && j < n; i--, j++)
		if (path[i][j] == 'Q')
			return 0;

	return 1;
}


// n为棋盘大小
// row为当前遍历的行数
void backtracking(int n, int row) {
	// 若遍历行数等于棋盘大小，则遍历结束
	if (row == n) {
		// 创建临时结果指针并初始化
		char **temp = (char **)malloc(n * sizeof(char));
		for (int i = 0; i < n; i++) {
			temp[i] = (char *)malloc((n + 1) * sizeof(char));
			for (int j = 0; j < n; j++)
				temp[i][j] = '.';
			temp[i][n] = '\0';
		}
		// 深拷贝至result
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = path[i][j];
		result[resultTop++] = temp;
	}

	for (int i = 0; i < n; i++) {
		if (isValid(row, i, n)) {
			path[row][i] = 'Q';
			backtracking(n, row + 1);
			// 回溯，将此位置设为null
			path[row][i] = '.';
		}
	}
}


char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
	path = (char **)malloc(n * sizeof(char *));
	result = (char ***)malloc(400 * sizeof(char **));
	pathTop = resultTop = 0;

	// 初始化二维数组path
	for (int i = 0; i < n; i++) {
		path[i] = (char *)malloc((n + 1) * sizeof(char));
		for (int j = 0; j < n; j++)
			path[i][j] = '.';
		path[i][n] = '\0';
	}

    backtracking(n, 0);

	*returnSize = resultTop;
	*returnColumnSizes = (int *)malloc(resultTop * sizeof(int));
	for (int i = 0; i < resultTop; i++)
		(*returnColumnSizes)[i] = n;
	return result;
}

