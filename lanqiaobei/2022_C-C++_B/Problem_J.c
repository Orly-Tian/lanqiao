// J.砍竹子
// Created by Administrator on 2025/4/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// height[i][j]中i代表第i根竹子，j代表修剪第j次
// height[i][j]为第i根竹子修剪j次后的高度
long long height[200020][8];


// 题目中的公式
long long sum(long long n) {
	long long result;
	// sqrtl()返回值为long long
	result = sqrtl(n / 2 + 1);
	return result;
}


int main() {
	int n;
	long long result = 0;
	scanf("%d", &n);
	// 将竹子(修剪0次)存入height数组的第一列
	for (int i = 0; i < n; i++) {
		scanf("%lld", &height[i][0]);
		// 遍历此竹子的行，修剪竹子并将高度存入本行
		for (int j = 1; height[i][j - 1] > 1; j++) {
			height[i][j] = sum(height[i][j - 1]);
			// 修剪次数++
			result++;
		}
	}

	// 遍历竹子
	for (long long i = 0; i < n - 1; i++)
		// 遍历此竹子的每一列
		for (long long j = 0; height[i][j] != 1; j++)
			// 遍历下一根竹子的每一列
			for (long long k = 0; height[i + 1][k] != 1; k++)
				// 若第i根竹子的第j步与第i+1根竹子的第k步的高度相同
				if (height[i][j] == height[i + 1][k]) {
					// 则这两步可以合并
					result--;
					// 并退出i+1的遍历，继续i的下一个j的遍历
					break;
				}

	printf("%lld", result);

	return 0;
}
