// 2379.得到K个黑块的最少涂色次数
// Created by Administrator on 2024/11/25.
// minimum-recolors-to-get-k-consecutive-black-blocks

// leetcode官方题解:
#include <string.h>

#define MIN(a, b) (a < b ? a : b)


int minimumRecolors(char* blocks, int k) {
    // 左右指针控制窗口，count记录当前窗口内白色数量
    int left = 0, right = 0, count = 0;
    // 第一个窗口，并记录白色数量
    while (right < k) {
        count += blocks[right] == 'W' ? 1 : 0;
        right++;
    }
    int result = count;
    int len = strlen(blocks);
    // 继续滑动窗口
    while (right < len) {
        // in和out操作
        count += blocks[right] == 'W' ? 1 : 0;
        count -= blocks[left] == 'W' ? 1 : 0;
        // 若后面的窗口有更小值则保留
        result = MIN(result, count);
        // 计数器
        left++;
        right++;
    }

    return result;
}


// AI版:
//      (滑动窗口,通过18/122个测试用例)
// int minimumRecolors(char* block, int k) {
//     int n = strlen(block);
//     if (n <= k) {
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (block[i] == 'W')
//                 count++;
//         }
//         return count;
//     }
//
//     int count = 0, max = 0;
//     for (int i = 0; i < k; i++) {
//         if (block[i] == 'W')
//             count++;
//     }
//     max = count;
//
//     for (int i = k; i < n; i++) {
//         if (block[i] == 'W')
//             count++;
//         if (block[i - k] == 'W')
//             count--;
//         if (count > max)
//             max = count;
//     }
//
//     return max - 1;
// }


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

