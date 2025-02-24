// 134.加油站
// Created by Administrator on 2025/2/23.
// https://leetcode.cn/problems/gas-station/
// https://www.bilibili.com/video/BV1jA411r7WX


int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int curGas = 0, totalGas = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
        curGas += gas[i] - cost[i];
        totalGas += gas[i] - cost[i];
        if (curGas < 0) {
            start = i + 1;
            curGas = 0;
        }
    }
    if (totalGas < 0)
        return -1;
    return start;
}
