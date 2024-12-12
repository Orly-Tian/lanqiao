// 643.子数组最大平均数
// Created by Administrator on 2024/11/18.
// https://leetcode.cn/problems/maximum-average-subarray-i/

#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0.0, ave = 0;

    for (int i = 0; i < numsSize; i++) {
        // 滑动数组求和
        sum += nums[i];

//         // 若不能满足下方滑动窗口output的条件,则直接计算ave
//         if (k == numsSize)
//             ave = sum / k;

        // 滑动窗口的第一个子数组
        if (i == k - 1)
            ave = sum / k;

        if (i >=  k) {
            // output操作
            int out = i - k;
            sum -= nums[out];

            // 计算ave并取最大值
            ave = ave > sum / k ? ave : sum/k;
        }
    }

    return ave;
}


/*  修改第一版:
 *      (滑动窗口)
 *  1.注:当满足output条件时(output = 0),即已经把数组第一个元素排除,
 *       也就是说将跳过第一个长度为l的子数组,需额外增加判断
 *
 */


// 第一版:
//      (滑动窗口,测试用例通过120/127)
//      无法处理滑动窗口的第一个子数组
// double findMaxAverage(int* nums, int numsSize, int k) {
//     double sum = 0.0, ave = 0;
//     for (int i = 0; i < numsSize; i++) {
//         // 滑动数组求和
//         sum += nums[i];
//         // 若不能满足下方滑动窗口output的条件,则直接计算ave
//         if (k == numsSize)
//             ave = sum / k;
//         // 滑动窗口未满,重复执行input操作
//         if (i < k)
//             continue;
//
//         // output操作
//         int out = i - k;
//         sum -= nums[out];
//
//         // 计算ave并取最大值
//         ave = ave > sum / k ? ave : sum/k;
//     }
//
//     return ave;
// }
//
//
// int main() {
//     int nums[10] = {9, 7, 3, 5, 6, 2, 0, 8, 1, 9};
//     printf("%f", findMaxAverage(nums, 10, 6));
// }
//
