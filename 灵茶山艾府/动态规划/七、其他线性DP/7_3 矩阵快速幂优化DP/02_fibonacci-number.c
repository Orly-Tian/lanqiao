// 509.斐波那契数
// Created by Administrator on 2025/2/25.
// https://leetcode.cn/problems/fibonacci-number/
// https://www.bilibili.com/video/BV1f5411K7mo/


int fib(int n) {
    if (n <= 1)
        return n;

    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }

    return dp[1];
}
