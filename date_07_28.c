//
// Created by Administrator on 2024/7/28.
// https://www.lanqiao.cn/problems/3624/learning/?page=20&first_category_id=1&sort=students_count&asc=0&difficulty=10&status=1&second_category_id=6


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int n,S;
    scanf("%d %d", &n, &S);
    int nums[n];
    for (int i=0;i<n;i++)
        scanf("%d", &nums[i]);

    int total=0,result=0;
    for (int i=0,j=0;i<n;i++) {
        total+=nums[i];
        while (total > S) {
            total-=nums[j];
            j++;
        }
        if ((i-j+1) > result)
            result = (i-j+1);
    }

    printf("%d", result);

    return 0;
}


/*  第一次做：
 *  1.不会，底部附一道双指针例题
 *  2.以上代码未发现有任何问题，但是lanqiao显示10个测试点全错，复制竞赛中心C++版本却能够正常提交
 *
 *
 *  竞赛中心：(双指针)
 *  1.初始化
 *  2.定义双指针循环，i为区间右端，j为区间左端，
 *    (for)当total随着i的变大而变大到超过S时，(while)左端点就向前一位
 *    并且把此时区间的长度记录，之后的每一次循环都和记录比较，若记录出现更大值，则用更大值覆盖掉原纪录
 *  3.输出结果
 */




// 请将两个有序列表[38,49,65,97]与[13,27,76]合并成为一个新的有序列表

#include <stdio.h>

int main() {
    int a[4] = {38, 49, 65, 97}, b[3] = {13, 27, 76}, c[10];
    int a_len=4,b_len=3;
    int i=0,j=0,k=0;

    // 三指针同时控制三个数组
    // a，b数组都还没有遍历结束
    while (i<a_len && j<b_len) {
        if (a[i] < b[j])
            // a数组赋值给c数组后,a和c自增
            c[k++] = a[i++];
        else
            // b数组赋值给c数组后,b和c自增
            c[k++] = b[j++];
    }

    // 若a数组还未遍历结束，则把a数组后面的每一个元素复制到c数组
    while (i<a_len)
        c[k++] = a[i++];
    // 若b数组还未遍历结束，则把b数组后面的每一个元素复制到c数组
    while (j<b_len)
        c[k++] = b[j++];

    // 输出结果
    for (int i=0;i<k;i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
