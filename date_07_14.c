//
// Created by Administrator on 2024/7/14.
// https://www.lanqiao.cn/problems/504/learning/?page=1&first_category_id=1&sort=students_count&asc=0&difficulty=20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    char ch,word[1000];
    int value[26]={0};


    scanf("%s", word);
    // for (int i=0;i<1000;i++) {
    //     scanf("%c", &word[i]);
    // }

    int area;
    for (int i=0;i<strlen(word);i++) {
        area = (int)word[i]-'a';
        value[area]++;
    }

    int max,count;
    for (int i=0;i<26;i++) {
        max=value[0];
        if (value[max] < value[i]) {
            value[max] = value[i];
            count = i;
        }
    }

    printf("%c\n", count+'a');
    printf("%d", max);

    return 0;
}

/*  第一次做：
 *  1.定义一个数组以接收单词
 *    定义一个长度[26]的组数存放a~z的数量
 *  2.遍历单词数组，按word[i]-'a'的位置将a~z数组计数
 *  3.比较出a~z数组最大值
 *  4.a~z数组的最大值的下标+'a'为出现最多次的字母
 *    a~z数组的最大值即为出现的次数
 *
 *
 *  问题：
 *  1.scanf()输入忘记取地址符&
 *  2.共13个测试点正确11个
 */



/*  竞赛中心：
 *  1.只定义a~z数组
 *  2.利用while((ch=getchar()) != '\n')来对单个字符处理
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int count[26]={0};
    char ch;
    while((ch=getchar())!='\n')
        count[ch-'a']++;

    int max=0;
    for(int i=1;i<26;i++)
        if(count[i]>count[max])
            max=i;

    printf("%c\n%d",max+'a',count[max]);

    return 0;
}
