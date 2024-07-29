//
// Created by Administrator on 2024/7/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str1[100];
    char str2[100];
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int len1, len2, result=0;

    scanf("%99s %99s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    result = (len1 > len2) ? len1+1 : len2+1;

    // 倒序复制进整形数组
    for (int i=0;i<len1;i++)
        a[len1-i-1] = str1[i]-'0';
    for (int i=0;i<len2;i++)
        b[len2-i-1] = str2[i]-'0';

    // 执行加法运算
    int carry = 0;
    for (int i=0;i<result;i++) {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }

    // 判断删除先导0
    while (result>1 && c[result-1]==0)
        result--;

    for (int i=result-1;i>=0;i--)
        printf("%d", c[i]);

    return 0;
}


/*  第一次做：
 *  1.不会
 *
 *
 *  竞赛中心：
 *  1.初始化，定义两个字符串数组,三个整形数组
 *  2.接收数字到字符串数组，并记录两数组长度
 *  3.将字符串数组复制进整形数组(倒序，因为加法须从最低位开始)
 *  4.执行加法运算：
 *    数组c[]的每一位赋值为a[]与b[]的和，
 *    但这一位仅为个位(即a与b的和 % 10)，
 *    把进位(即a与b的和 / 10)存放在一个变量中加到下次运算
 *  5.在上面为了进位提前将result增加了一位，判断之后将result减去一位，避免最后一位没有进位而倒序打印出现先导0
 *  6.倒序打印结果
 *
 *
 *
 */
