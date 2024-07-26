//
// Created by Administrator on 2024/7/26.
// https://www.lanqiao.cn/problems/310/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=10&second_category_id=6

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    int count=0;
    scanf("%d", &n);

    if (n >= 2)
        count++;

    for (int i=3;i<=n;i++) {
        for (int j=2;j<i;j++) {
            if (i % j == 0) {
                break;
            }
            else if (j == i-1) {
                count++;
                break;
            }
        }
    }

    printf("%d", count);

    return 0;
}


/*  第一次做：
 *  1.初始化
 *  2.若n为2，则计数为1
 *  3.循环判断从3开始，外层(3~n)为所需判断的数，内层(2~次数-1)为此数的因数
 *    判断(此数%因数)是否为0，若Ture，则跳出内循环,
 *    若内层循环的因数直到外层所需判断的数-1都没有跳出，则说明此数为质数，计数++
 *  4.输出
 *
 */
