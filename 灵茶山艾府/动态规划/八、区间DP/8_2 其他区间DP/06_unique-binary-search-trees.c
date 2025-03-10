// 96.不同的二叉搜索树
// Created by Administrator on 2025/3/10.
// https://leetcode.cn/problems/unique-binary-search-trees
// https://www.bilibili.com/video/BV1eK411o7QA


int numTrees(int n) {
    // 定义dp数组：dp[i]表示i个节点有dp[i]种不同的二叉搜索树
    int dp[n + 1];

    // 若有0个节点，则只有1个二叉搜索树，即空树
    // 后面的dp值都可根据此初始化推出
    dp[0] = 1;

    // 遍历n，即在n范围内若仅有i个节点
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        // 遍历i，即计算当j为头节点时二叉搜索树的个数
        for (int j = 1; j <= i; j++) {
            // 二叉搜索树的个数为左子树的个数dp[j - 1] * 右子树的个数dp[i - j]
            // 左子树节点个数从0到i-1，右子树的节点个数从i-1到0
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}
