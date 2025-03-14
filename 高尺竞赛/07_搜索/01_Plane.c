// 01.飞机降落
// Created by Administrator on 2025/3/13.
// 2023年B组C省赛
// https://www.lanqiao.cn/problems/3511/learning/?page=1&first_category_id=1&name=%E9%A3%9E%E6%9C%BA

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))


typedef struct {
	// t[i]为可以降落时间
	// d[i]为可以盘旋时间
	// l[i]为需要降落时间
	int t, d, l;
} Plane;


void swap(Plane *p1, Plane *p2);
int solve(int admit, int n, Plane *plane);


int main(int argc, char* argv[]) {
	// 输入飞机的组数
	int T;
	scanf("%d", &T);

	while (T--) {
		// 输入每组有几架飞机
		int n;
		scanf("%d", &n);

		// 建立飞机数组
		Plane *plane = (Plane *)malloc(n * sizeof(Plane));
		// 读入本组飞机的状态
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &plane[i].t, &plane[i].d, &plane[i].l);

		int flag = solve(0, n, plane);

		if (flag == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}


// admin:当前飞机允许降落的最早时间，即前一架飞机降落结束时间
// n:当前未处理的飞机数量
// *plane:当前处理的飞机
int solve(int admit, int n, Plane *plane) {
	// 若所有飞机已遍历结束，返回true
	if (n == 0)
		return 1;

	// 遍历此组的飞机
	for (int i = 0; i < n; i++) {
		// 若当前飞机到达时间+可以盘旋时间大于等于允许降落的最早时间
		if (plane[i].t + plane[i].d >= admit) {
			// 则说明此飞机符合降落条件，将此飞机和当前待处理的第一架飞机交换位置
			swap(plane+i, plane);
			// 此飞机成功交换顺序后，递归遍历剩下未处理的飞机
			// admin更新为上一架飞机降落结束时间与当前飞机可以降落时间的最大值+当前飞机需要降落时间
			// n更新为n+1
			// plane更新为以下一架飞机开始的数组
			if (solve(MAX(admit, plane->t) + plane->l, n - 1, plane + 1))
				return 1;
			// 若递归失败，回溯出来后重新换回原来的位置
			swap(plane + i, plane);
		}
	}
	// 返回false
	return 0;
}


void swap(Plane *p1, Plane *p2) {
	Plane temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
