//
// Created by Administrator on 2024/10/29.
// https://leetcode.cn/problems/find-pivot-index/


int pivotIndex(int* nums, int numsSize) {

    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total+=nums[i];
    }

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (2 * sum + nums[i] == total)
            return i;
        sum+=nums[i];
    }

    return -1;
}

/*  第一次做:(讨论过)
 *  1.计算total
 *  2.遍历数组,
 *      记录每个元素的前缀和
 *      判断上一个元素的前缀和*2加此元素(中心元素)是否等于total
 *          若相等,则返回此元素索引
 *  3.遍历结束未找到,返回-1
 *
 */
