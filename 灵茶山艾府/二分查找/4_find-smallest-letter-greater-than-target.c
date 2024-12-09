// 744.寻找比目标字母大的最小字母
// Created by Administrator on 2024/12/9.
// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/


#include <stdio.h>
#include <stdlib.h>


// leetcode官方题解:
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize - 1;

    if (letters[lettersSize - 1] <= target)
        return letters[0];

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }

    return letters[left];
}


// 第一版:
// 左闭右闭
// char nextGreatestLetter(char* letters, int lettersSize, char target) {
//     int left = 0, right = lettersSize - 1;
//
//     if (letters[lettersSize - 1] <= target)
//         return letters[0];
//
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (letters[mid] > target)
//             right = mid - 1;
//         else if (letters[mid] < target)
//             left = mid + 1;
//         else
//             return letters[mid + 1];
//     }
//
//     return letters[left];
// }
//
//
int main() {
    char letters[5] = {'e', 'e', 'e', 'e', 'n'};
    printf("%c", nextGreatestLetter(letters, 5, 'e'));

    return 0;
}


/*  第一版问题:
 *      (二分查找,时间复杂度O(log n),通过134/167测试用例)
 *      1.数组元素可重复,若middle值查找到target,
 *        middle+1的值依然与middle值相等则不能正确输出大于target的最小值
 *
 */


