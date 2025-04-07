// E.X进制减法
// Created by Administrator on 2025/4/7.
// https://www.lanqiao.cn/problems/2108/learning/?page=1&first_category_id=1&name=%E8%BF%9B%E5%88%B6

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MaxSize 100005
#define MOD 1000000007

int num1[MaxSize] = {0}, num2[MaxSize] = {0};


int main() {
	// num1_X为num1的位数
	// num2_X为num2的位数
	int N, num1_X, num2_X;
	scanf("%d", &N);

	// 倒序存储每位的数字
	scanf("%d", &num1_X);
	for (int i = num1_X - 1; i >= 0; i--)
		scanf("%d", &num1[i]);
	scanf("%d", &num2_X);
	for (int i = num2_X - 1; i >= 0; i--)
		scanf("%d", &num2[i]);

	// result为最终结果
	// base为当前位的权重，初值为1
	long long result = 0, base = 1;
	// 遍历两数的最大位数
	for (int i = 0; i < fmax(num1_X, num2_X); i++) {
		// 记录当前位进制，当前进制为两数在此位的数字最大值+1，且当前位进制最小为2
		int weight = fmax(fmax(num1[i], num2[i]) + 1, 2);
		// 计算num1和num2当前位的差*权重，并累加到result中
		result = (result + (num1[i] - num2[i]) * base) % MOD;
		// 更新权重，下一位的权重为当前权重*当前进制
		base = base * weight % MOD;
	}

	printf("%lld", result % MOD);

	return 0;
}


/* 问：
 *		那么，在X进制减法这道题中，为什么每位进制为当前位两数最大值加1，
 *		最后得出来的差就一定是最小值呢？
 * 答:
 *		因为在每一位我们取的进制都为允许取到的最小进制，根据进制与位权的关系，
 *		通过贪心的思维易得，最终得出来的每一位的累加起来的结果差值亦为最小值
 * /
