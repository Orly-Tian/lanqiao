//
// Created by Administrator on 2024/7/24.
// https://www.lanqiao.cn/problems/531/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=10&second_category_id=6

#include <stdio.h>
#include <stdlib.h>

struct Students {
    int number;
    int Chinese;
    int Math;
    int English;
    int tatal;
};

int main(int argc, char *argv[])
{
    // 请在此输入您的代码

    int n;
    scanf("%d", &n);

    struct Students stu[n];
    for (int i=0;i<n;i++) {
        scanf("%d %d %d", &stu[i].Chinese, &stu[i].Math, &stu[i].English);
        stu[i].number = i+1;
        stu[i].tatal = stu[i].Chinese + stu[i].Math + stu[i].English;
    }

    struct Students temp;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (stu[j].tatal < stu[j+1].tatal) {
                temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }

    for (int i=0;i<n-1;i++) {
        if (stu[i].tatal == stu[i+1].tatal) {
            if (stu[i].Chinese < stu[i+1].Chinese) {
                temp = stu[i];
                stu[i] = stu[i+1];
                stu[i+1] = temp;
            }
            /*
            else if (stu[i].Chinese == stu[i].Chinese) {
              if (stu[i].Math < stu[i+1].Math) {
                temp = stu[i];
                stu[i] = stu[i+1];
                stu[i+1] = temp;
              }
              else if (stu[i].Math == stu[i+1].Math) {
                if (stu[i].English < stu[i+1].English) {
                  temp = stu[i];
                  stu[i] = stu[i+1];
                  stu[i+1] = temp;
                }
              }
            }
            */
        }
    }

    for (int i=0;i<5;i++) {
        printf("%d %d\n", stu[i].number, stu[i].tatal);
    }

    return 0;
}


/*  第一次做：
 *  1.定义学生结构体，包含每个学生的学号，每科成绩，总成绩
 *  2.初始化，创建结构体数组存储学生数据
 *  3.根据总成绩冒泡排序
 *  4.遍历数组两两比较，若总成绩相同，前者语文低则交换顺序，前者语文高则不动
 *  5.输出前五名的学号，总成绩
 *
 *
 *  问题：
 *  1.scanf()输入要加取地址符&
 *  2.认真读题，总成绩相同仅需比较语文成绩，语文成绩相同则不需要额外操作，因为冒泡排序具有稳定性，学号顺序不变
 *
 */
