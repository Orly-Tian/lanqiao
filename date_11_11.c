// 283.移动零
// Created by Administrator on 2024/11/11.
// https://leetcode.cn/problems/move-zeroes/


// 第一版：
//      (通过25/74个测试用例)
// void moveZeroes(int* nums, int numsSize) {
//     int end = numsSize - 1;
//     for (int i = 0; i < numsSize; i++) {
//         if (i == end || i == end + 1 || i == end - 1)
//             break;
//         if (nums[i] == 0) {
//             for (int j = i; j < numsSize - 1; j++) {
//                 nums[j] = nums[j + 1];
//             }
//             nums[end--] = 0;
//         }
//     }
// }
//
// int main() {
//     int nums[2] = {0, 1};
//     moveZeroes(&nums, 2);
// }
//
