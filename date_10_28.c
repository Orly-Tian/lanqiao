//
// Created by Administrator on 2024/10/28.
// https://leetcode.cn/problems/two-sum/solutions/434597/liang-shu-zhi-he-by-leetcode-solution/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;
                int *result = malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


/*  第一次做:(暴力穷举)
 *  1.确定第一个数据,遍历第一个数据后的每一个数据,判断两数之和是否为指定值
 *
 *
 *  问题:
 *  1.首次做leetcode,不用编写main()函数接收数据,仅需要关注核心算法函数
 *  2.搞清楚函数内每个参数的含义并充分利用
 *
 */

