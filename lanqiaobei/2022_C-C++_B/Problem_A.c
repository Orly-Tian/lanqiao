// A.九进制转十进制
// Created by Administrator on 2025/4/4.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int num_9 = 2022;
	int value = 0;
	for (int i = 0; i < 4; i++) {
		int num_i = num_9 % 10;
		int value_i = num_i * pow(9, i);
		value += value_i;
		num_9 /= 10;
	}

	printf("%d", value);

	return 0;
}
