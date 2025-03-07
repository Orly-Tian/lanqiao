// 2.分巧克力
// Created by Administrator on 2025/3/7.
// 2017年省赛

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	// n块巧克力，k个人
	int n, k;
	scanf("%d %d", &n, &k);
	// 每块巧克力的尺寸
	int length[n], width[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &length[i], &width[i]);

	// 结果范围为1-1e5
	int left = 1, right = 1e5;
	int result = 0;
	// 二分查找[左闭右闭]
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int count = 0;

		// 遍历每块巧克力
		for (int i = 0; i < n; i++)
			// 第i块巧克力可以分成的块数为(它的长除正方形边长)*(它的宽除正方形边长)
			count += (length[i] / mid) * (width[i] / mid);

		// 若把所有巧克力分完之后的块数大于等于总人数，说明有可能分成的正方形小了
		if (count >= k) {
			left = mid + 1;
			result = mid;
		}
		// 否则一定为正方形尺寸太大了
		else
			right = mid - 1;
	}

	printf("%d", result);

	return 0;
}
