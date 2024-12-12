// 2841.几乎唯一子数组的最大和
// Created by Administrator on 2024/12/2.
// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/

#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)


long long maxSum(int* nums, int numsSize, int m, int k) {
	// 遍历数组
	long long sum = 0, maxSum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];

		// 单独处理第一个窗口
		if (i == k - 1) {
			int count = 1;
			for (int j = 0; j < i; j++) {
				for (int k = j + 1; k <= i; k++) {
					if (nums[j] == nums[k])
						break;
					if (k == i)
						count++;
				}
			}
			if (count >= m)
				maxSum = MAX(maxSum, sum);
		}

		// 滑动窗口已满
		if (i >= k) {
			int out = i - k;
			sum -= nums[out];

			// 判断非重复值
			int count = 1;
			for (int j = out + 1; j < i; j++) {
				// 仅判断相邻元素是否为非重复值
				// if (nums[j] != nums[j + 1])
				// 	count++;
				// 暴力穷举任意两个值判断是否为非重复值
				for (int k = j + 1; k <= i; k++) {
					if (nums[j] == nums[k])
						break;
					if (k == i)
						count++;
				}
			}

			// 若重复值条件满足
			if (count >= m) {
				maxSum = MAX(sum, maxSum);
			}
		}
	}

	return maxSum;
}


int main() {
	int nums[7] = {5, 9, 9, 2, 4, 5, 4};
	printf("%lld", maxSum(nums, 7, 1, 3));
}


/*	第一次做:(思路,时间复杂度O(n * ((k+1)*k)/2)
 *			(通过753/767个测试用例,时间复杂度太高)
 *		1.遍历数组,设置滑块
 *		2.遍历滑块,若非重复值数量大于m,则记录滑块和
 *		3.比较滑块和,取最大值
 *
 *	问题:
 *		1.仍旧需要单独处理第一个窗口		[已解决]
 *		2.仅判断相邻两数是否为非重复值,而非滑窗内的非重复值数量	[已解决]
 *
 */
