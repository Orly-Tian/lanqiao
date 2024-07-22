//
// Created by Administrator on 2024/7/21.
// https://www.lanqiao.cn/problems/250/learning/?page=1&first_category_id=1&sort=problem_id&asc=1&difficulty=20&second_category_id=6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    char chars_1[100];
    gets(chars_1);

    for (int i=strlen(chars_1)-1;i>=0;i--) {
        printf("%c", chars_1[i]);
    }

    return 0;
}


/*  第一次做：
 *  1.定义两个数组，一个字符变量
 *  2.循环通过字符变量接收字符，存入数组1
 *  3.嵌套循环，外循环0~strlen(arr1)，内循环strlen(arr2)，
 *    通过内外循环变量交换数组数据,arr2即为arr1倒序
 *  4.输出arr2
 *
 *  问题：
 *  1.输入错误，底部将展示四种输入方式
 *  2.复杂度太高
 */


/*  竞赛中心：
 *  1.输入后循环变量倒着输出即可
 */






// 四种不同的输入方式
#include <stdio.h>
#include <string.h>

int main() {
    char ch[10]={0};

    // 第一种：scanf("%c")循环输入
    //      不能控制当前数组长度
    // for (int i=0;i<10;i++) {
    //     scanf("%c", &ch[i]);
    // }

    // 第二种：for循环getchar()输入
    // for (int i=0;i<10;i++) {
    //     ch[i]=getchar();
    //     if (ch[i] == '\n')
    //         break;
    // }

    // 第三种：while循环getchar()输入
    // char char1;
    // int i=0;
    // while ((ch[i]=getchar()) != '\n') {
    //     i++;
    // }

    // 第四种：get()函数
    //      有参数无返回值，在原数组中操作
    // gets(ch);


    for (int i=0;i<10;i++) {
        printf("%c", ch[i]);
    }

    return 0;
}
