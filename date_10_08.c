//
// Created by Administrator on 2024/10/8.
// https://www.lanqiao.cn/problems/1445/learning/?page=1&first_category_id=1&difficulty=20&sort=students_count&asc=0

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    long memoryTotal = 256 * 1024 * 1024;
    int memory = 4;
    printf("%ld", memoryTotal/memory);
  
    return 0;
}


/*  单位换算：
 *      1MB = 1024KB
 *      1KB = 1024B
 *      1Byte = 8bit
 *
 */
