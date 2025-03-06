// 1.二分搜索
// Created by Administrator on 2025/3/6.
// 代码随想录：https://www.bilibili.com/video/BV1fA4y1o715
// 高尺竞赛：https://www.bilibili.com/video/BV1YtcFemEBb?spm_id_from=333.788.player.switch&vd_source=4c293aa27f67a76d01553a3b9517eaf3&p=8

#include <stdio.h>


// 左闭右闭
int BinarySearch(int *nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < nums[mid])
			right = mid - 1;
		else if (target > nums[mid])
			left = mid + 1;
		else if (target == nums[mid])
			return mid;
	}
	return -1;
}


int main() {
	int nums[10];
	for (int i = 1; i <= 10; i++) {
		nums[i - 1] = i;
		printf("%d ", i);
	}

	int result = BinarySearch(nums, 10, 1);
	printf("\n%d", result);

	return 0;
}


