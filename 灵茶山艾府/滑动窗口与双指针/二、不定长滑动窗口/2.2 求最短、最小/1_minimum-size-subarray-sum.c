// 209.长度最小的子数组
// Created by Administrator on 2024/12/13.
// https://leetcode.cn/problems/minimum-size-subarray-sum/
// https://www.bilibili.com/video/BV1tZ4y1q7XE?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3

#include <limits.h>
#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)


int minSubArrayLen(int target, int* nums, int numsSize) {
	int left = 0, sum = 0, result = INT_MAX;

	// 循环控制右边界
	for (int right = 0; right < numsSize; right++) {
		sum += nums[right];

		// 若窗口的和满足条件
		while (sum >= target) {
			int count = right - left + 1;
			result = MIN(result, count);
			// 窗口左边界向右缩并循环判断是否仍然满足条件
			sum -= nums[left++];
		}
	}

	// 若result仍为极大值则整个数组和未达到条件,返回0
	return result == INT_MAX ? 0 : result;
}


// 第一版:
// int minSubArrayLen(int target, int* nums, int numsSize) {
//     // result为返回结果
//     // maxSum为整个数组的总和
//     int result = 0, maxSum = 0;
//
//     // left与right双指针
//     for (int left = 0; left < numsSize; left++) {
//         int right = left, sum = 0;
//         int count = 0;
//
//         // maxSum记录整个数组的总和
//         maxSum += nums[left];
//         // 窗口内的和
//         while (sum < target && right < numsSize) {
//             sum += nums[right++];
//             count++;
//         }
//
//         // 将第一个窗口的长度赋值至结果
//         if (left == 0)
//             result = count;
//
//         // 若条件满足,则取最小值
//         // 必须满足条件是为了防止数组末尾仅有最后一个元素时,若未条件判断,则最终结果总是1
//         if (sum >= target)
//             result = MIN(result, count);
//     }
//
//     // 若数组长度总和未达到target值,则返回0
//     if (maxSum < target)
//         return 0;
//
//     // 返回结果
//     return result;
// }


int main() {
    int nums[6] = {2, 3, 1, 2, 4, 3};
    printf("%d", minSubArrayLen(7, nums, 6));

    return 0;
}



/*	第一版:
 *		(通过了18/21个测试用例,超时,时间复杂度O(n * k))
 *
 */
