// 55.跳跃游戏
// Created by Administrator on 2025/2/20.
// https://leetcode.cn/problems/jump-game/
// https://www.bilibili.com/video/BV1VG4y1X7kB

#include <stdbool.h>


bool canJump(int* nums, int numsSize) {
    if (numsSize == 1)
        return true;

	int cover = 0;
	for (int i = 0; i <= cover; i++) {
		cover = (i + nums[i]) > cover ? (i + nums[i]) : cover;
		if (cover >= numsSize - 1)
			return true;
	}
	return false;
}
