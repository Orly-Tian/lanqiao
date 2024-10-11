//
// Created by Administrator on 2024/10/11.
// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518581337161646080&page=0

#include <stdio.h>


int main() {
    int a, b;
    long result = 1;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    for (int i = 1; i <= sum; i++) {
        result *= i;
    }

    printf("%ld", result);

    return 0;
}

