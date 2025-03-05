// 1.最大公约数(欧几里得算法)
// Created by Administrator on 2025/3/4.
// https://www.bilibili.com/video/BV1YtcFemEBb
// 欧几里得算法详解：https://www.bilibili.com/video/BV19r4y127fu/

#include <stdio.h>


int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


int main() {
	printf("%d", gcd(100, 124));
}
