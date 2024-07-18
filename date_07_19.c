//
// Created by Administrator on 2024/7/19.
// https://www.lanqiao.cn/problems/690/learning/?page=1&first_category_id=1&sort=pass_rate&asc=0&difficulty=10&second_category_id=3

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码

    for (int i=0;i<=100;i++) {
        for (int j=0;j<=100;j++) {
            for (int k=0;k<=100;k++) {
                if (i*8+j*6+k*4==600 && i+j*3+k*4==280 && i+j+k==100)
                    printf("%d", j);
            }
        }
    }

    return 0;
}

/*  第一次做：
 *  1.百马百担，穷举即可
 *
 *
 *  竞赛中心：
 *  1.列方程组解矩阵
 */
