//
// Created by Administrator on 2024/7/17.
// https://www.lanqiao.cn/problems/592/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=20&second_category_id=3

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int count=0;

    for (int i=0;i<=2020;i++) {
        for (int j=i;j>0;j=j/10) {
            if (j%10 == 2)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}
