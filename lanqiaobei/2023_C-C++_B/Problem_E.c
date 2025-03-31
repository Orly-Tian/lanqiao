// E.接龙数列
// Created by Administrator on 2025/3/31.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_MAX 1e5 + 5


// dp[i]表示为尾数为i的数字已接龙的最大长度
int dp[10];


int main() {
	int n;
	scanf("%d", &n);

	char str[10];
	int m = 0;
	for (int i = 0; i < n; i++) {
		// 将数字保存为字符串
		scanf("%s", str);
		// 提取出字符串的首尾字符，并转化为十进制整型
		int x = str[0] - '0', y = str[strlen(str) - 1] - '0';
		// 将此数字的首位，即以该数首位为末尾dp[x]所接龙的最大值 与 此数字的末尾dp[y]的接龙最大值
		// 取两数最大值更新至dp[y]
		dp[y] = fmax(dp[x] + 1, dp[y]);
		// 保存历史最大值
		m = fmax(m, dp[y]);
	}

	// 历史最大值m为此数列当前最大接龙数，数列长度减去最大接龙数即需要移除数字的最少数量
	printf("%d", n - m);

	return 0;
}
