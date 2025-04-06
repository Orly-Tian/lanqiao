// D.修剪灌木
// Created by Administrator on 2025/4/5.
// https://www.lanqiao.cn/problems/2107/learning/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int n;
	scanf("%d", &n);

	// 蓝桥云课题解：
	// 灌木白天生长傍晚修剪，所能生长的最大值的时间为修剪此灌木的当天，
	// 也就是说生长到最大值的周期为修剪后到下次修剪的当天，由于修剪完一轮会调转方向
	// 即，某灌木可以长高的最大值为其位置据左端点与右端点最大值的2倍
	//
	for (int i = 1; i <= n; i++)
		// 遍历此数组，并求此灌木据左端点与右端点最大值的2倍
		printf("%d\n", (int)fmax(i - 1, n - i) * 2);

	return 0;
}


// 模拟暴力
//		通过了3/8个(37.5%)个测试用例
// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	// n = 10000;
// 	int trees[n + 5];
// 	int result[n + 5];
// 	for (int i = 0; i < n; i++) {
// 		trees[i] = 0;
// 		result[i] = 0;
// 	}
//
// 	for (int k = 0; k < 2; k++) {
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++)
// 				trees[j] += 1;
// 			trees[i] = 0;
// 			for (int j = 0; j < n; j++)
// 				result[j] = fmax(result[j], trees[j]);
// 		}
// 		for (int i = n - 1; i >= 0; i--) {
// 			for (int j = 0; j < n; j++)
// 				trees[j] += 1;
// 			trees[i] = 0;
// 			for (int j = 0; j < n; j++)
// 				result[j] = fmax(result[j], trees[j]);
// 		}
// 	}
//
// 	for (int i = 0; i < n; i++)
// 		printf("%d\n", result[i]);
//
// 	return 0;
// }

