// 2529.正整数和负整数的最大计数
// Created by Administrator on 2024/12/10.
// https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/

#define MAX(a, b) (a > b ? a : b)


int search(int *nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			return mid;
	}

	return left;
}


int maximumCount(int* nums, int numsSize) {
	int i = search(nums, numsSize, 0);
	int j = search(nums, numsSize, 1);

	return MAX(i, numsSize - j);
}



