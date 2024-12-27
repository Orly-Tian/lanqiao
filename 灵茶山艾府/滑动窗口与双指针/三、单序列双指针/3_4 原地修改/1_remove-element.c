// 27.移除元素
// Created by Administrator on 2024/11/8.
// https://leetcode.cn/problems/remove-element/

#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}


/*  第三版:(双指针,方法同26题类似)
 *  1.创建k函数指向待处理元素
 *  2.用i遍历数组,若nums[i] != val,则将此值赋值给nums[k++]
 *  3.赋值完后k即是数组长度,返回k
 *
 */


// 第一次做:
//      (匹配成功一个值后,将后面所有值依次向前移一位,时间复杂度O(n^2))
// int removeElement(int* nums, int numsSize, int val) {
//     int k = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == val) {
//             for (int j = i ; j < numsSize - 1; j++)
//                 nums[j] = nums[j+1];
//             i--;
//         }
//         else
//             k++;
//     }
//
//     return k;
// }



// 第二次做:
//      (匹配成功一个值后,仅将后面的第一个值向前覆盖掉此值,然后i--复位,碰到连续的匹配值将死循环)
// int removeElement(int* nums, int numsSize, int val) {
//     int k = 0;
//     for (int i = 0; i < numsSize - 1; i++) {
//         if (nums[i] == val) {
//             nums[i] = nums[i+1];
//             i--;
//         }
//         else
//             k++;
//     }
//
//     return k;
// }
//
//
// int main() {
//     int nums[5] = {1, 2, 2, 3, 1};
//     int k = removeElement(nums, 5, 2);
//     for (int i = 0; i < k; i++)
//         printf("%d", nums[i]);
// }

