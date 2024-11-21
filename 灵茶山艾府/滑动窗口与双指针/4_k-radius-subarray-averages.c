// 2029.半径为k的子数组平均值
// Created by Administrator on 2024/11/20.
// https://leetcode.cn/problems/k-radius-subarray-averages/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>


int* getAverages(int* nums, int numSize, int k, int* returnSize) {
    
}


// 第一版：
//      (暴力穷举,时间复杂度O(n * k),通过27/40个测试用例)
// int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
//     int *ave = (int *)malloc(numsSize * sizeof(int));
//     for (int i = 0; i < numsSize; i++) {
//         if (i < k)
//             ave[i] = -1;
//
//         int sum = 0;
//         if (i >= k && i < numsSize - k) {
//             for (int j = i - k; j <= i + k; j++)
//                 sum += nums[j];
//             ave[i] = sum / (2 * k + 1);
//         }
//
//         if (i >= numsSize - k)
//             ave[i] = -1;
//     }
//
//     *returnSize = numsSize;
//
//     return ave;
// }
//
//
// int main() {
//     int nums[9] = {7, 4, 3, 9, 1, 8, 5, 2, 6}, returnSize;
//     int *ave;
//     ave = getAverages(nums, 9, 3, &returnSize);
//     for (int i = 0; i < 9; i++)
//         printf("%d ", ave[i]);
// }
//
