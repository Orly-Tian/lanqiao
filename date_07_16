//
// Created by Administrator on 2024/7/16.
// https://www.lanqiao.cn/problems/502/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=20&second_category_id=3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n,value,jige=0,youxiu=0;

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &value);

        if (value>=60 && value<=100)
            jige++;
        if (value>=85 && value<=100)
            youxiu++;
    }


    float jige_lv,youxiu_lv;
    jige_lv=(jige*100.0)/n;
    youxiu_lv=(youxiu*100.0)/n;

    printf("%.0f%%\n%.0f%%", jige_lv, youxiu_lv);

    return 0;
}

/*  第一次做：
 *  1.接收人数，及循环单独接收成绩
 *  2.通过成绩确定位次并计数
 *  3.通过整型*100.0放大并自动切换为浮点型，以四舍五入
 *
 *  资料：
 *  1.通过放大到四舍五入的前一位＋0.5四舍五入
 *  2.C++17以后皆能够%.0f自动四舍五入
 */
