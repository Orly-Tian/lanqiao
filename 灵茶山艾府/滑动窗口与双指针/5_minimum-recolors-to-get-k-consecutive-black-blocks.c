// 2379.得到K个黑块的最少涂色次数
// Created by Administrator on 2024/11/25.
// minimum-recolors-to-get-k-consecutive-black-blocks

#include <string.h>


// AI版:
//      (滑动窗口,通过18/122个测试用例)
int minimumRecolors(char* block, int k) {
    int n = strlen(block);
    if (n <= k) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (block[i] == 'W')
                count++;
        }
        return count;
    }

    int count = 0, max = 0;
    for (int i = 0; i < k; i++) {
        if (block[i] == 'W')
            count++;
    }
    max = count;

    for (int i = k; i < n; i++) {
        if (block[i] == 'W')
            count++;
        if (block[i - k] == 'W')
            count--;
        if (count > max)
            max = count;
    }

    return max - 1;
}


// 第一版:
//      (滑动窗口)
// int minimumRecolors(char* blocks, int k) {
//     int n = strlen(blocks);
//     int num = 0, result = 0;
//     for (int i = 0; i < n; i++) {
//         if (i < k) {
//             if (blocks[i] == 'W')
//                 result = num++ < result++ ? num : result;
//         }
//         if (i >= k) {
//             int out = i - k;
//             if (blocks[out] == 'W') {
//                 result = num-- < result ? num : result;
//             }
//         }
//     }
//     return result;
// }


int main() {
    char *str = "WBBWWBBWBW";
    minimumRecolors(str, 7);
}

