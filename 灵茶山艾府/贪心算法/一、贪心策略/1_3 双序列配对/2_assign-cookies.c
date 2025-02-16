// 455.分发饼干
// Created by Administrator on 2025/2/16.
// https://leetcode.cn/problems/assign-cookies/
// https://www.bilibili.com/video/BV1MM411b7cq

#include <stdlib.h>


int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int i = 0;
    for (int j = 0; j < sSize; j++) {
        if (i < gSize && g[i] <= s[j]) {
            i++;
        }
    }
    return i;
}
