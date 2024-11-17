// 1456.定长子串中元音的最大数目
// Created by Administrator on 2024/11/16.
// https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <stdio.h>
#include <string.h>

#define MAX(a, b) (a > b ? a : b)

int maxVowels(char* s, int k) {
    // 定义结果与元音
    int ans = 0, vowel = 0;

    // 遍历数组
    for (int i = 0; s[i]; i++) {
        // 从i开始进入窗口
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
            || s[i] == 'o' || s[i] == 'u') {
            vowel++;
        }
        // 若窗口长度不足k,则重复执行进入窗口
        if (i < k - 1) {
            continue;
        }

        // 更新最大值
        ans = MAX(ans, vowel);

        // 定义离开窗口
        char out = s[i - k + 1];
        // 若离开窗口的元素含有元音,则vowel自减
        if (out == 'a' || out == 'e' || out == 'i'
            || out == 'o' || out == 'u') {
            vowel--;
        }
    }

    return ans;
}


/*  leetcode灵茶山艾府题解:
 *      (双指针滑动窗口)
 *  1.入:循环变量i控制元素进入窗口,若未到窗口长度,则再次执行进入窗口操作
 *  2.更新:更新答案
 *  3.出:变量out = i-k+1控制左侧窗口的出,匹配值离开窗口则vowel--
 */


// 第一版:
//      (穷举遍历,通过103/107个测试用例,运行超时)
// int maxVowels(char* s, int k) {
//     int count, result = 0;
//     for (int i = 0; i < strlen(s) - k + 1; i++) {
//         count = 0;
//         for (int j = i; j < i + k; j++) {
//             if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i'
//                 || s[j] == 'o' || s[j] == 'u') {
//                 count++;
//             }
//         }
//         result = count > result ? count : result;
//         // if (count > result)
//         //     result = count;
//     }
//
//     return result;
// }
//
//
// int main() {
//     char *s = "abciiidef";
//     printf("%d", maxVowels(s, 3));
// }
//
