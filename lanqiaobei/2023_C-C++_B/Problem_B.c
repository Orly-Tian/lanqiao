// B.01串的熵
// Created by Administrator on 2025/3/29.
// https://www.bilibili.com/video/BV1j24y1w7RR/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int main() {
	long n = 23333333;
	for (long i = 0; i <= n / 2; i++) {
		long j = n - i;
		long double result = -1.0 * i * i / n * log2l(1.0 * i / n) - 1.0 * j * j / n * log2l(1.0 * j / n);
		if (fabsl(result - 11625907.5798) < 0.0001)
			printf("%ld\n", i);
	}
}
