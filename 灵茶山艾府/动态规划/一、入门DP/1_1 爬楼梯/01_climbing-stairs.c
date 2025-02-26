// 70.爬楼梯
// Created by Administrator on 2025/2/26.
// https://leetcode.cn/problems/climbing-stairs/
// https://www.bilibili.com/video/BV17h411h7UH


int climbStairs(int n) {
    if (n <= 3)
        return n;

    int dp[2];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        int temp = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = temp;
    }

    return dp[1];
}

