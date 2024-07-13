//
// Created by Administrator on 2024/7/13.
// https://www.lanqiao.cn/problems/202/learning/?page=1&first_category_id=1&difficulty=30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    char ch[100];
    int flag=0;

    for (int i=0;i<100;i++) {
        ch[i] = getchar();
        if (ch[i] == '\n')
            break;
    }

    for (int i=0;i<strlen(ch);i++) {
        for (int j=i+1;j<strlen(ch);j++) {
            if (ch[i] == ch[j]) {
                flag=1;
                break;
            }
        }
    }

    if (strlen(ch) == 1)
        printf("YES");
    else if (flag == 0)
        printf("YES");
    else if (flag == 1)
        printf("NO");


    return 0;
}


/*  第一次做：
 *  1.定义一个用以存放字符串的数组，使用for循环接收字符存入数组内，直到\n结束循环
 *  2.冒泡排序，相邻元素两两比较
 *  3.排序后相邻两两比较是否相等，记flag
 *  4.通过flag输出结果
 *
 *
 *  问题：
 *  1.接收字符函数为 ch[i] = getchar(),无参数有返回值
 *  2.字符串长度函数为 strlen()
 *  3.测试点4个仅有3个正确
 *  4.无法忽略英文字母大小写，后通过判断所比较的元素若为小写，则(与后者比较结果相等)或(+32与后者相等)皆为真,
 *                                      元素若为大写，则(与后者比较结果相等)或(-32与后者相等)皆为真。
 *    此时字符串已通过冒泡排序好，但仍无法确定小写字母与大写字母的位置关系，且测试点仅正确2个，遂放弃。
 *  5.竞赛中心似乎也未解决大小写不敏感问题,但测试点全部正确，测试点似乎未考虑大小写。
 */



/*  竞赛中心：
 *  1.定义一个字符串数组，通过字符串输入
 *  2.外层循环为a，范围0--strlen(ch)
 *      内层循环为b，范围a+1--strlen(ch)
 *    穷举比较，记flag
 *  3.通过flag输出结果
 */
