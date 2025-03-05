// 1.青蛙跳台阶
// Created by Administrator on 2025/3/3.
// https://www.bilibili.com/video/BV1YtcFemEBb?spm_id_from=333.788.player.switch&vd_source=4c293aa27f67a76d01553a3b9517eaf3&p=4
// 代码随随想录：https://www.bilibili.com/video/BV17h411h7UH

#include <stdio.h>


int main() {
	int n;
	scanf("%d", &n);

	int dp[n + 1];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%d", dp[n]);

}
