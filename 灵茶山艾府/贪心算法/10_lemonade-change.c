// 860.柠檬水找零
// Created by Administrator on 2025/2/24.
// https://leetcode.cn/problems/lemonade-change/
// https://www.bilibili.com/video/BV12x4y1j7DD

#include <stdbool.h>


bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (five >= 0) {
            // 遇到5刀
            if (bills[i] == 5)
                five++;
            // 遇到10刀
            else if (bills[i] == 10) {
                ten++;
                five--;
                if (five < 0)
                    return false;
            }
            // 遇到20刀
            else {
                // 先找10刀再找5刀
                if (ten && five) {
                    ten--;
                    five--;
                }
                // 找三张5刀
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        else
            return false;
    }

    return true;
}


int main() {
    int bills[10] = {5,5,5,10,5,5,10,20,20,20};
    bool result = lemonadeChange(bills, 10);
}
