// 997.有序数组的平方
// Created by Administrator on 2024/12/12.
// https://leetcode.cn/problems/squares-of-a-sorted-array/
// https://www.bilibili.com/video/BV1QB4y1D7ep?spm_id_from=333.788.player.switch&vd_source=4c293aa27f67a76d01553a3b9517eaf3

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>


int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));
	*returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;
    int i = numsSize - 1;
    while (i >= 0) {
		if (nums[left] * nums[left] > nums[right] * nums[right]) {
			result[i] = nums[left] * nums[left];
			i--; left++;
		}
		else {
			result[i] = nums[right] * nums[right];
			i--; right--;
		}
	}

	return result;
}


/*  代码随想录:
 *		(左右双指针,时间复杂度O(n))
 *	类似于接水问题,左右双指针,将平方值更大的倒序放入新数组,最后双指针缩入中间最小值
 *
 */
