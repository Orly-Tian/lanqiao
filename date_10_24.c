//
// Created by Administrator on 2024/10/24.
// https://www.lanqiao.cn/problems/19949/learning/?contest_id=214

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char S[9999];
        int length = 0;
        while ((S[length] = getchar()) != '\n') {
            length++;
        }
        for (int j = 0; j <= length; j++) {
            if (j == length-1) {
                if (S[j] == '9') {
                    printf("%s0", S);
                }
                else {
                    S[j]++;
                    printf("%s\n", S);
                }
            }
        }
    }

    return 0;
}

