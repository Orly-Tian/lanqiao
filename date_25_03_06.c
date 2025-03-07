// 16.阶乘求值[省模拟赛]
// Created by Administrator on 2025/3/6.
// https://www.lanqiao.cn/problems/20246/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=20&name=%E6%A8%A1%E6%8B%9F%E8%B5%9B

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	// 请在此输入您的代码
	int n;
	scanf("%d", &n);
	long long result = 1;
	for (int i = n; i > 1; i--) {
		// result *= i;
		// result %= 1000000007;
		result = (result * i) % 1000000007;
	}
	printf("%lld", result);

	return 0;
}
