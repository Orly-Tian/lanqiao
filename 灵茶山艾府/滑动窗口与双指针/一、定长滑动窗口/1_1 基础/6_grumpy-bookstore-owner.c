// 1052.爱生气的书店老板
// Created by Administrator on 2024/11/30.
// https://leetcode.cn/problems/grumpy-bookstore-owner/

#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)


int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int windowSum = 0, windowsMax = 0, sum = 0;
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i]) {
            windowSum += customers[i];
        } else
            sum += customers[i];
        if (i >= minutes) {
            int out = i - minutes;
            if (grumpy[out])
                windowSum -= customers[out];
        }
        windowsMax = MAX(windowSum, windowsMax);
    }

    return sum + windowsMax;
}


int main() {
    int customers[8] = {1, 0, 1, 2, 1, 1, 7, 5};
    int grumpy[8] = {0, 1, 0, 1, 0, 1, 0, 1};
    int result = maxSatisfied(customers, 8, grumpy, 8, 3);
    printf("%d", result);
}


/*  第一版：
 *      (滑动窗口，时间复杂度O(n))
 *  1.遍历customers数组,分别计算在minutes为长度的滑动窗口和(即顾客在此区间的不满意度和)与整天的顾客满意度和
 *  2.记录滑动窗口最大值,即老板应该使用超能力的阶段
 *  3.用记录的顾客满意度加滑动窗口最大值,即使用超能力后的最大满意度
 *
 */

