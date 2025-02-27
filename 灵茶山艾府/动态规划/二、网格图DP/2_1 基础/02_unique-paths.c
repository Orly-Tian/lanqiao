// 62.不同路径
// Created by Administrator on 2025/2/27.
// https://leetcode.cn/problems/unique-paths/
// 代码随想录：https://www.bilibili.com/video/BV1ve4y1x7Eu
// leetcode官方视频题解：https://www.bilibili.com/video/BV1cp4y167qx/


int uniquePaths(int m, int n) {
	// DP数组的值表示为到达坐标mn时的路径数
    int dp[m][n];

	// 初始化DP，使得第0行第0列的值均为1
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			// 到达第ij个坐标的路径为上一格和左一格的路径之和
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	// 返回mn坐标的路径数
	return dp[m - 1][n - 1];
}
