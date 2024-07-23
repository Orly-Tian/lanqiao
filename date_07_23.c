//
// Created by Administrator on 2024/7/23.
// https://www.lanqiao.cn/problems/320/learning/?page=1&first_category_id=1&sort=problem_id&asc=1&difficulty=20&second_category_id=6

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    int x[n],y[n];
    for (int i=0;i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int min[n],max[n],x_v;
    min[0]=x[0];
    max[0]=y[0];
    for (int i=0;i<n-1;i++) {
        if (x[i] > x[i+1]) {
            min[0]=x[i+1];
            max[0]=x[i+1];
            x_v=i+1;
        }
    }

    for (int i=0;i<n;i++) {
        if (y[x_v] >= x[i])
            max[0]=y[i];
    }

    printf("%d %d", min[0], max[0]);

    return 0;
}


/*  第一次做：
 *  1.初始化，定义输入接收模块
 *    x[]为区间的左断点，y[]为区间的右端点
 *  2.循环比较所有左端点，左端点的最小值赋值给min[0]，对应的右端点赋值给max[0]，
 *    并记录这个区间在x[],y[]中的下标
 *  3.比较此区间的右端点与其他区间的左端点，若前者>后者，则将max[0]赋值为后者的右端点
 *  4.min[0],max[0]即为第一个合并后的区间
 *
 *
 *  问题：
 *  1.仅能求出第一个个合并后的区间
 *
 */


/*  竞赛中心：
 *  1.用二维数组
 *
 */
