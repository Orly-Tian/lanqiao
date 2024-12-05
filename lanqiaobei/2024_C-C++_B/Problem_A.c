// 蓝桥杯2024年省赛C/C++大学B组真题
// Created by Administrator on 2024/12/4.
// https://www.lanqiao.cn/courses/2786/learning/?id=2870024

#include <stdio.h>

int main() {
	int count = 0;
	for (int i = 49; i > 0; i--) {
		count += i;
	}

	int count_not = 0;
	for (int i = 6; i > 0; i--) {
		count_not += i;
	}

	printf("%d", count - count_not);

  return 0;
}

