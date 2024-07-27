//
// Created by Administrator on 2024/7/27.
// https://www.lanqiao.cn/problems/497/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=10&status=1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
    }

    int max,min,tatal=0;
    max=min=nums[0];
    for (int i=0;i<n;i++) {
        if (max < nums[i])
            max = nums[i];
        if (min > nums[i])
            min = nums[i];
        tatal+=nums[i];
    }

    float avg;
    avg = (tatal*1.0)/n;

    printf("%d\n%d\n%.2f", max, min, avg);

    return 0;
}


/*  第一次做：
 *  1.初始化
 *  2.比较出最大值最小值，并计算总值
 *  3.计算平均值(注意数据类型的转换)
 *  4.输出
 *
 */
