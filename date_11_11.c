// 283.移动零
// Created by Administrator on 2024/11/11.
// https://leetcode.cn/problems/move-zeroes/


void moveZeroes(int* nums, int numsSize) {
    // left指向待处理的非零元素
    // right指向需遍历的全部元素
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right]) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
        }
        right++;
    }
}


/*  leetcode官方题解:(双指针)
 *      1.定义两个变量分别指向待处理非零元素与全部元素
 *      2.通过right变量遍历数组
 *          若此元素为非零元,则交换两指针元素,且非零元指针+1
 *        循环遍历数组变量+1
 *
 *      即,若遍历到的元素为0时,left指针不动,right指针才会右移一位
 *  若遍历到的元素非0时,才会将left(也就是在0元素处等待处理)指针与right指针的元素交换位置
 *
 */


// 第一版：
//      (通过25/74个测试用例)
// void moveZeroes(int* nums, int numsSize) {
//     // 从数组尾部开始依次向前补零
//     int end = numsSize - 1;
//     for (int i = 0; i < numsSize; i++) {
//         // 判断是否遍历到非零元素的末尾
//         if (i == end || i == end + 1 || i == end - 1)
//             break;
//         // 若检测到0,则将后面的每个元素向前移一位
//         if (nums[i] == 0) {
//             for (int j = i; j < numsSize - 1; j++) {
//                 nums[j] = nums[j + 1];
//             }
//             // 末尾补零,并将end变量向前移一位
//             nums[end--] = 0;`
//         }
//     }
// }
//
// // 测试失败的用例
// int main() {
//     int nums[2] = {0, 1};
//     moveZeroes(&nums, 2);
// }
//
