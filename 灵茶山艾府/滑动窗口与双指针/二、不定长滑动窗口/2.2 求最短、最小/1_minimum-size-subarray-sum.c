// 209.长度最小的子数组
// Created by Administrator on 2024/12/13.
// https://leetcode.cn/problems/minimum-size-subarray-sum/

#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)


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
//
//
// int main() {
//     int nums[6] = {2, 3, 1, 2, 4, 3};
//     printf("%d", minSubArrayLen(7, nums, 6));
//
//     return 0;
// }
//


/*	第一版:
 *		(通过了18/21个测试用例,超时,时间复杂度O(n * k))
 *
 */
