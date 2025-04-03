// B.小球反弹
// Created by Administrator on 2024/12/4.
//

#include <stdio.h>
#include <math.h>


int main() {
	long longSide = 343720, shortSide = 233333;
	long time = 1;
	while (1) {
		if (time * 15 % longSide == 0
			&& time * 17 % shortSide == 0)
			break;
		time++;
	}
	long double result = 2 * time * sqrt(pow(15, 2) + pow(17, 2));
	printf("%.2Lf", result);
}

