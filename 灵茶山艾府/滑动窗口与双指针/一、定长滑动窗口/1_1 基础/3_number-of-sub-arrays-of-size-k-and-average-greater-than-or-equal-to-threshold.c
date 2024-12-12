// 1343.大小为K且平均值大于等于阈值的子数组数目
// Created by Administrator on 2024/11/19.
// https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

#include <stdio.h>

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    float sum = 0, ave = 0, count = 0;
    // 滑动窗口开始
    for (int i = 0; i < arrSize; i++) {
        // 变量i控制滑动窗口的input操作
        sum += arr[i];
        if (i == k - 1) {
            ave = sum / k;
            // 第一个子数组符合条件则count++
            if ((sum / k) >= threshold)
                count++;
        }

        // 滑动窗口长度足够时
        int out = 0;
        if (i >= k) {
            // 变量out控制滑动窗口的output操作
            out = i - k;
            sum -= arr[out];
            ave = sum / k;
        }

        // 窗口大小为k且平均值满足条件则count+1
        if (i - out == k && ave >= threshold)
            count++;
    }

    return count;
}


// 第一版:
//      (滑动窗口,通过68/69个测试用例)
//
// int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
//     float sum = 0, ave = 0, count = 0;
//     // 滑动窗口开始
//     for (int i = 0; i < arrSize; i++) {
//         // 变量i控制滑动窗口的input操作
//         sum += arr[i];
//         if (i == k - 1)
//             ave = sum / k;

//         // 滑动窗口长度足够时
//         if (i >= k) {
//             // 变量out控制滑动窗口的output操作
//             int out = i - k;
//             sum -= arr[out];
//             ave = sum / k;
//         }

//         // 条件满足则计数器+1
//         if (ave >= threshold)
//             count++;
//     }
//
//     return count;
// }
//
//
 int main() {
     int arr[8] = {2, 2, 2, 2, 5, 5, 5, 8};
     printf("%d", numOfSubarrays(arr, 8, 3, 4));
 }
