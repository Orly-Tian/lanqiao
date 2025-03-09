// 343.整数拆分
// Created by Administrator on 2025/3/1.
// https://leetcode.cn/problems/integer-break/
// https://www.bilibili.com/video/BV1Mg411q7YJ

#include <math.h>
#include <stdlib.h>


int integerBreak(int n) {
	// 若n小于2则无法拆分，若等于2，则只能拆分成1*1
	if (n <= 2)
		return 1;

	// dp数组：dp[i]表示为将i拆分后的最大乘积
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	// i从3开始遍历到n
	for (int i = 3; i <= n; i++) {
		dp[i] = 0;
		// j从1开始遍历到i以拆分
		for (int j = 1; j <= i / 2; j++)
			// dp[i]为以下三个值的最大值：
			// 1.j拆分的两数之积：j * (i - j)
			// 2.j拆分的多数之积：j * dp[i - j]，其中dp[i - j]表示为后面这个数被拆分过的最大乘积
			// 1.dp[i]在之前循环中的最大值
			dp[i] = fmax(fmax(j * (i - j), j * dp[i - j]), dp[i]);
	}

	return dp[n];
}
