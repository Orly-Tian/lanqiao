//
// Created by Administrator on 2024/10/7.
// https://www.bilibili.com/video/BV1Q14y1B7DH/?spm_id_from=333.1007.0.0&vd_source=4c293aa27f67a76d01553a3b9517eaf3
// 【左程云】算法讲解002 从社会实验到入门提醒


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double calculateGini(double wealth[], int n);
void experiment(int n, int t);


int main() {
    printf("一个社会的基尼系数是一个位于0~1之间的小数\n");
    printf("基尼系数为0代表所有人的财富完全一样\n");
    printf("基尼系数为1代表有1个人掌握了全社会的所有财富\n");
    printf("基尼系数越小，代表社会财富分布越均衡，基尼系数越大则说明财富分布越不均衡\n");
    printf("在2022年，世界各国的平均基尼系数为0.44\n");
    printf("目前普遍认为，当基尼系数达到0.5时\n");
    printf("就意味着社会贫富差距非常大，分布极不均匀\n");
    printf("社会可能会因此陷入危机，比如大量的犯罪或者经历社会动荡\n");
    printf("\n");
    printf("测试开始：\n");

    int n = 100;
    int t = 10000;
    printf("人数：%d\n", n);
    printf("轮数：%d", t);
    experiment(n, t);
    printf("测试结束！\n");

    return 0;
}


// 实验过程
void experiment(int n, int t) {
    // 初始化每个人的财富均为100
    double wealth[n];
    bool hasMoney[n];
    for (int i = 0; i < n; i++) {
        wealth[i] = 100;
        hasMoney[i] = false;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++)
            if (wealth[j] > 0)
                hasMoney[j] = true;
        // 若此人财富不为0，则对他人进行财富分配
        for (int j = 0; j < n; j++) {
            if (hasMoney[j]) {
                int other = j;
                do {
                    // 生成随机数
                    other = (int)(rand() % n);
                } while (other == j);
                wealth[j]--;
                wealth[other]++;
            }
        }
    }

    // 排序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            int temp;
            if (wealth[j] > wealth[j+1]) {
                temp = wealth[j+1];
                wealth[j+1] = wealth[j];
                wealth[j] = temp;
            }
        }
    }

    // 输出
    printf("\n列出每个人的财富(从贫穷到富有):\n");
    for (int i = 0; i < n; i++) {
        printf("%.0f\t", wealth[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
    printf("基尼系数为：%f\n", calculateGini(wealth, n));
}


// 计算基尼系数
double calculateGini(double wealth[], int n) {
    // 定义社会财富差值总和
    double sumOfAbsoluteDiff = 0;
    // 定义社会财富总和
    double sumOfWealth = 0;
    // 定义社会总人口量
    for (int i = 0; i < n; i++) {
        // 社会财富总和
        sumOfWealth += wealth[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            // 社会财富差值总和：每个数据对所有数据的绝对值的和
            // <math.h>的abs()函数用于返回一个int值的绝对值，fabs()函数用于返回一个float值的绝对值
            sumOfAbsoluteDiff += fabs(wealth[i] - wealth[j]);
    }
    // 基尼系数的计算公式：
    return sumOfAbsoluteDiff / (2 * n * sumOfWealth);
}
