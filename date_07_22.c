//
// Created by Administrator on 2024/7/22.
// https://www.lanqiao.cn/problems/252/learning/?page=1&first_category_id=1&sort=problem_id&asc=1&difficulty=20&second_category_id=6


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int num,value1=-1,value2=-1;
    scanf("%d", &num);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]+arr[j]==num) {
                value1=i;
                value2=j;
                break;
            }
        }
        if (value1!=-1 && value2!=-1)
            break;
    }

    printf("%d %d", value1, value2);


    return 0;
}


/*  第一次做：
 *  1.初始化，设计好输入的接收模块
 *  2.嵌套循环，外部从i=0开始，内部从j=i+1开始
 *    暴力穷举判断条件是否成立
 *  3.条件成立将两个索引记录并输出
 *  
 *
 *  问题：
 *  1.如果有多种结果，需要找出最小的满足条件的索引值
 *    所以一旦条件成立，须跳出循环，
 *    内外循环都要跳出
 *
 */

