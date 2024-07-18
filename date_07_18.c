//
// Created by Administrator on 2024/7/18.
// https://www.lanqiao.cn/problems/583/learning/?page=1&first_category_id=1&sort=pass_rate&asc=0&difficulty=20&second_category_id=3

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int value=0;

    for (int i=1;i<=2020;i++) {
        if (i%4==0 && i%6==0)
            value++;
    }

    printf("%d", value);

    return 0;
}

/*  第一次做：
 *  1.最简单的一题，穷举即可
 *
 *
 *  竞赛中心：
 *  1.直接将除以两数的最小公倍数即可
 */

#include <stdio.h>

int main() {

    printf("%d", 2020/12);

    return 0;

}

