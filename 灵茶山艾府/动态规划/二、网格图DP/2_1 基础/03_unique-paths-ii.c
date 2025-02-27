// 63.不同路径2
// Created by Administrator on 2025/2/27.
// https://leetcode.cn/problems/unique-paths-ii/
// https://www.bilibili.com/video/BV1Ld4y1k7c6

#include <stdlib.h>


// 第一版：
//      通过了14/42个测试用例，猜测为数据溢出
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    // 二维数组为m行n列
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;

    // DP的含义为到mn坐标的路径数
    int dp[m][n];

    // 初始化DP数组的两条边，遇到障碍则停止
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1)
            break;
        dp[0][i] = 1;
    }

    // 递推公式，到达第ij个坐标的路径为上一格和左一格的路径之和
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            // 条件为未遇到障碍
            if (obstacleGrid[i][j] != 1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
}

