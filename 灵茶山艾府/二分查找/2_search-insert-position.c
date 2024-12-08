// 35.搜索插入位置
// Created by Administrator on 2024/12/7.
// https://leetcode.cn/problems/search-insert-position/
// 代码随想录视频讲解:https://www.bilibili.com/video/BV1fA4y1o715?vd_source=4c293aa27f67a76d01553a3b9517eaf3&spm_id_from=333.788.player.switch

#include <stdio.h>


// 左闭右闭
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    // 小于等于符合区间定义
    while (left <= right) {

        // 前者有越界的风险,后者则可以避免越界
        // int mid = (right + left) / 2;
        int mid = left + (right - left) / 2;

        // target在middle值的左侧
        if (nums[mid] > target)
            // 更新左区间的右边界
            // 且因闭区间,middle值已判断过,新区间的右边界应更新至 mid - 1
            right = mid - 1;

        // target在middle值的右侧
        else if (nums[mid] < target)
            // 更新右区间的左边界
            // 且因闭区间,middle值已判断过,新区间的右边界应更新至 mid + 1
            left = mid + 1;

        // middle的值即为target
        else
            return mid;
    }

    // 返回left,因为左闭区间,所以即使未找到target值,返回小于target最大值的位置+1
    return left;
}


// 左闭右开
// int searchInsert(int *nums, int numsSize, int target) {
//     int left = 0, right = numsSize;
//     while (left < right) {
//         // 避免越界
//         int mid = left + (right - left) / 2;
//         // int mid = (right + left) / 2;
//
//         // target在middle值的左侧
//         if (nums[mid] > target)
//             // 更新左区间的右边界
//             // 且因左闭右开区间,middle已经判断过,新区间的右边界更新至 mid
//             right = mid;
//
//         // target在middle值的右侧
//         else if (nums[mid] < target)
//             // 更新右区间的左边界
//             // 且因左闭右开区间,middle已经判断过,新区间的左边界更新至 mid + 1
//             left = mid + 1;
//
//         else
//             return mid;
//     }
//
//     // 返回left,因为左闭区间,所以即使未找到target值,返回小于target最大值的位置+1
//     return left;
// }


int main() {
    int nums[4] = {1, 3, 5, 6};
    printf("%d", searchInsert(nums, 4, 2));

    return 0;
}

