// 1.年龄问题
// Created by Administrator on 2025/3/2.
// 2017年省赛
// https://www.bilibili.com/video/BV1YtcFemEBb?vd_source=4c293aa27f67a76d01553a3b9517eaf3&p=2&spm_id_from=333.788.player.switch

#include <math.h>
#include <stdbool.h>
#include <stdio.h>


int isAge(int age) {
	int age3 = pow(age, 3);
	int age4 = pow(age, 4);
	int standard[10] = {0};

	// 将年龄立方的所有数字保存至standard
	while (age3) {
		int i = age3 % 10;
		standard[i] = i;
		age3 /= 10;
	}
	// 将年龄四次幂的所有数字保存至standard
	while (age4) {
		int i = age4 % 10;
		standard[i] = i;
		age4 /= 10;
	}

	// 因一共仅10个数字，所以只需判断是否standard中每个位置都被写入数字
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (standard[i] == i)
			count++;
	}
	if (count == 10)
		return true;
	return false;
}


int main() {
	// 确定大致范围，遍历该范围
	for (int i = 10; i < 30; i++)
		// 先进行一步判断，尽量避免无意义的暴力
		if (pow(i, 3) >= 1000 && pow(i, 3) <= 9999
			&& pow(i, 4) >= 100000 && pow(i, 4) <= 999999)
			// 函数判断值是否符合条件
			if (isAge(i))
				printf("%d", i);

	return 0;
}
