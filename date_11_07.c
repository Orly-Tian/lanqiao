// 26.删除有序数组中的重复项
// Created by Administrator on 2024/11/7.
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] != nums[i+1]) {
            nums[k++] = nums[i+1];
        }
    }

    return k;
}


/*  第一次做:
 *  1.用i遍历数组,并新建一个k变量指向第一个重复元素
 *  2.若nums[i]与nums[i+1]不相等时,则
 *      将nums[i+1]赋值给nums[k];
 *      k++;
 *  3.返回k,k的值即为数组长度
 *
 *
 *  问题:
 *  1.遍历数组范围应为i < numsSize-1,
 *    因为下面需要判断到i+1,否则将堆溢出
 *  2.k初始化为1,所以后面k的值直接就是待覆盖的重复元素位置,
 *    赋值完后k的值也正是数组长度
 */
