// 704.二分查找
// Created by Administrator on 2024/12/8.
// https://leetcode.cn/problems/binary-search/


// 左闭右闭
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target)
            right = mid - 1;

        else if (nums[mid] < target)
            left = mid + 1;

        else
            return mid;
    }

    return -1;
}
