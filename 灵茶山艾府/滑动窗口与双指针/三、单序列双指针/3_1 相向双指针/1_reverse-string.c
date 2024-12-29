// 反转字符串之二题
// Created by Administrator on 2024/12/26.
// https://www.bilibili.com/video/BV1dT411j7NN?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3



// 344.反转字符串
// Created by Administrator on 2024/12/27.
// https://leetcode.cn/problems/reverse-string/


#include <string.h>

void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++, j--;
    }
}

int main() {
    char s[5] = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s, 5);
}



// 541.反转字符串2
// Created by Administrator on 2024/12/26.
// https://leetcode.cn/problems/reverse-string-ii/
// https://www.bilibili.com/video/BV1dT411j7NN?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3


void reverse(char *s, int i, int k) {
    while (i < k) {
        char temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        i++, k--;
    }
}


char* reverseStr(char* s, int k) {
    for (int i = 0; i < strlen(s); i += 2 * k) {
        if (i + k <= strlen(s))
            reverse(s, i, i + k - 1);
        else
            reverse(s, i, strlen(s) - 1);
    }

    return s;
}


// char* reverseStr(char* s, int k) {
//     // i为保持在2k内部的遍历指针
//     // index为整个字符串的遍历指针
//     // count为2k的倍数
//     int i = 0, index = 0, count = 0;
//
//     // i在2k区间内&&index在字符串区间内
//     while (i < 2 * k && index < strlen(s)) {
//         // 2k区间左右向内收缩且交换位置
//         int left = index, right = (count * 2 * k)+ k - i - 1;
//         if (i < k && left < right) {
//             char temp = s[left];
//             s[left] = s[right];
//             s[right] = temp;
//         }
//
//         // 更新计数器
//         i++, index++;
//
//         // 若i值超过2k的范围,则重置
//         if (i == 2 * k)
//             i = 0, count++;
//     }
//
//     return s;
// }


/*  第一次做:
 *      (通过9/60个测试用例)
 *
 *  问题:
 *      循环变量i只在2k内遍历循环,则只能在第一个2k区间内给left和right正确赋值
 *          通过添加index变量,用于遍历整个字符串解决
 *      区间的right变量赋值不正确(right = index + k - i - 1)
 *          right的值应为区间内的左端-i-1,而index为已经收缩后的left变量
 *          所以又加入count变量,用于记录此时循环至第几个2k区间,count值即为此刻2k区间的左端点
 *
 */
