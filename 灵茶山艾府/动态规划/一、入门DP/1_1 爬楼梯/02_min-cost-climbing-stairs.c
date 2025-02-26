// 746.使用最小花费爬楼梯
// Created by Administrator on 2025/2/26.
// https://leetcode.cn/problems/min-cost-climbing-stairs/
// https://www.bilibili.com/video/BV16G411c7yZ

#define MIN(a, b) (a < b ? a : b)


int minCostClimbingStairs(int* cost, int costSize) {
    // 顶楼为第costSize层
    int dp[costSize + 1];

    // 从下标为0或下标为1的台阶开始
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= costSize; i++) {
        // 每一步都是前一步或前两步的最小花费
        dp[i] = MIN(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    // 返回顶层所花费用
    return dp[costSize];
}
