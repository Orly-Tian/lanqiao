// 11.盛最多水的容器
// Created by Administrator on 2024/11/12.
// https://leetcode.cn/problems/container-with-most-water/description/


int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int area, max_area = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            area = height[left] * (right - left);
            left++;
        }
        else {
            area = height[right] * (right - left);
            right--;
        }

        if (area > max_area)
            max_area = area;
    }

    return max_area;
}


/*  leetcode官方题解:
 *      1.定义左右指针
 *      2.计算此刻面积,并将边长较短的指针向内移一位
 *      3.记录最大面积
 */


// 第一版:
//      (通过55/63个测试用例)
//      通过水平面的上升,若左右边长皆超过水平面,则计算此刻的面积
//      若左右边长被水平面超过,则左or右指针向内移动
// int maxArea(int* height, int heightSize) {
//     int left = 0, right = heightSize - 1;
//     int line = 1;
//     int area, max_area = 0;
//     int max = height[0];
//     for (int i = 1; i < heightSize; i++) {
//         if (height[i] > max)
//             max = height[i];
//     }
//
//     while (line <= max) {
//         if (line > height[left])
//             left++;
//         if (line > height[right])
//             right--;
//
//         if (height[left] > height[right])
//             area = (right - left) * height[right];
//         else
//             area = (right - left) * height[left];
//
//         if (area > max_area)
//             max_area = area;
//
//         line++;
//     }
//
//     return max_area;
// }
//
