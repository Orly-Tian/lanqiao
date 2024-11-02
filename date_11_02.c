//
// Created by Administrator on 2024/11/2.
// https://leetcode.cn/problems/median-of-two-sorted-arrays/

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *nums3;
    nums3 = (int *)malloc((nums1Size + nums2Size) * sizeof(int));

    // 遍历数组，将nums1与nums2中的元素顺序存入新数组
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            nums3[k++] = nums1[i++];
            // nums3[k] = nums1[i];
            // i++; k++;
        } else {
            nums3[k++] = nums2[j++];
            // nums3[k] = nums2[j];
            // j++; k++;
        }
    }
    // 若较短的数组遍历结束，则将另一个数组接着遍历直至结束
    while (i < nums1Size) nums3[k++] = nums1[i++];
    while (j < nums2Size) nums3[k++] = nums2[j++];

    // 定义中位数，通过顺序数组的索引返回中位数
    double mid;
    if (k % 2 == 1)
        mid = nums3[k / 2];
    else
        mid = (nums3[k / 2 - 1] + nums3[k / 2]) / 2.0;

    // 释放内存
    free(nums3);

    return mid;
}


/*  第一次做：
 *  1.新建结果数组
 *  2.遍历数组，将nums1与nums2顺序存入新数组
 *  3.通过索引返回新数组的中位数
 *
 *
 *  问题：(通过AI解决)
 *  1.遍历两个数组，不能像链表一样用or运算(date_10_29 leetcode第2题)，
 *    应该用and运算后再单独处理剩下的
 *  2.通过索引返回顺序数组的中位数，应注意到数组索引从0开始
 *
 */

