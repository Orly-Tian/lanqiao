//
// Created by Administrator on 2024/10/10.
// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518581694528933888&page=0

#include <stdio.h>

int main() {
    int begin[6];
    int began[6] = {6, 6, 6, 6, 6, 6};
    int n;
    for (int i = 0; i < 6; i++)
        scanf("%d", &begin[i]);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (i == (1)) {
            for (int j = 0; j < 6; j++) {
                if (began[j] == begin[j]) {
                    printf("%d ", (began[j]-1));
                    began[j]--;
                }
                else {
                    printf("%d ", (began[j]));
                    began[j]--;
                }
            }

        }
    }

    return 0;
}
