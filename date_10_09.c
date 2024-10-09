//
// Created by Administrator on 2024/10/9.
// https://www.lanqiao.cn/problems/645/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=20

#include <stdio.h>
#include <stdlib.h>

#define Num 50

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    float price[Num];
    float percent[Num];
    char name[10];
    float total = 0;
    for (int i = 0; i < Num; i++) {
        scanf("%s\t%f\t%f", &name, &price[i], &percent[i]);
        printf("%.2f\n", price[i]);
        total += price[i];
    }

    printf("%f", total);



    return 0;
}
