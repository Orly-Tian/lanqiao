//
// Created by Administrator on 2024/7/26.
// https://www.lanqiao.cn/problems/539/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=10&second_category_id=6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
    }

    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            int temp;
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
            else if (nums[j] == nums[j+1]) {
                nums[j+1] = 1001;
            }
        }
    }

    int count=0;
    for (int i=0;i<n;i++) {
        if (nums[i] < 1001)
            count++;
    }

    printf("%d\n", count);
    for (int i=0;i<n;i++) {
        if (nums[i] < 1001)
            printf("%d ", nums[i]);
    }


    return 0;
}


/*  第一次做：
 *  1.初始化
 *  2.冒泡排序，并且如果相比较两者相同，则将后者赋值为1001
 *  3.遍历数组，对数组中小于1001的值计数
 *  4.输出小于1001的值
 *
 *  问题：
 *  1.底部展示C语言获取随机数
 *
 */


/*  竞赛中心：
 *  1.初始化，定义数组a[1000]
 *  2.接收到的值赋值给变量t,若a[t] == 0，则a[t] = t，并计数
 *  3.输出计数，输出数组a[]内所有非零值
 *
 */






// 以下为展示C语言中获取随机数
// int main() {
//     int a;
//
//     // srand()函数用于给rand()函数设定种子
//     srand((unsigned)time(NULL));
//
//     // rand()函数获取随机数
//     a=rand();
//
//     // 输出100~1000的随机数
//     printf("%d", a%901 + 100);
//
//     return 0;
// }
