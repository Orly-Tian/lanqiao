//
// Created by Administrator on 2024/10/24.
// https://www.lanqiao.cn/problems/19949/learning/?contest_id=214

#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {
//     // 请在此输入您的代码
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i <= n; i++) {
//         char S[5] = {0};
//         int length = 0;
//         char ch;
//         while ((ch = getchar()) != '\n') {
//             S[length] = ch;
//             length++;
//         }
//         for (int j = 0; j < length; j++) {
//             if (j == length-1) {
//                 if (S[j] == '9') {
//                     printf("%s0\n", S);
//                 }
//                 else {
//                     S[j]++;
//                     printf("%s\n", S);
//                 }
//             }
//         }
//     }
//
//     return 0;
// }
//


/*  第一次做：
 *  1.初始化
 *  2.若此数尾数为9，则加一位0
 *    若此数尾数非9，则此数+1
 *  3.输出
 *
 *
 *  竞赛中心：
 *  1.初始化
 *  2.若此数非0，则加一位0
 *    若此数为0，则此数+1(因为C中整型不能有前导0)
 *  3.输出
 */


int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("1\n");
        }
        else printf("%lld\n",10*a[i]);
    }

    return 0;
}
