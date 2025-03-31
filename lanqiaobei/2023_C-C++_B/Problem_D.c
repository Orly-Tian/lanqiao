// 飞机降落
// Created by Administrator on 2025/3/27.
// https://www.lanqiao.cn/problems/3511/learning/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define n_MAX 11


int T[n_MAX], D[n_MAX], L[n_MAX];
int used[n_MAX] = {0};
int n, have_answer;


// x为当前已降落了几架飞机
// time为当前时间
void dfs(int x, int time) {
	if (x == n) {
		have_answer = 1;
		return;
	}

	// 遍历本组飞机
	for (int i = 1; i <= n; i++) {
		// 若飞机还未降落，且飞机允许降落时间在当前时间后
		if (!used[i] && time <= T[i] + D[i]) {
			// 允许降落并记录
			used[i] = 1;
			// 递归下一架飞机，且更新时间
			//					若当前时间飞机还未到，则飞机降落时间为当前时间
			//					若当前时间飞机已到，则飞机降落时间为飞机到场时间
			dfs(x + 1, fmax(T[i], time) + L[i]);
			// 当前顺序不能降落所有飞机，回溯函数并记录
			used[i] = 0;
		}
	}
}


int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &T[i], &D[i], &L[i]);
			used[i] = 0;
		}

		// 结果状态
		have_answer = 0;
		// 递归函数
		dfs(0, 0);

		// 若结果为真
		if (have_answer)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
