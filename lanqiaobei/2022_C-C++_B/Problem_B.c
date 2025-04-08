// 2.顺子日期(date模板)	2022_C-C++_B组省赛
// Created by Administrator on 2025/4/8.
// https://www.lanqiao.cn/problems/2096/learning/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	// 请在此输入您的代码
	int sum=0;
	// 预处理每个月的天数
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// 存放循环中临时处理的年月日
	int year, month, day;

	// 循环年份
	for(year = 2022 ; year <= 2022 ; year++) {
		// 若为闰年，则更改预处理数组中2月为29天
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			months[2] = 29;
		else
			months[2] = 28;

		// 循环月份
		for (month = 1; month <= 12; month++) {
			int a[5] = {0};
			// 将月份存入数组
			if (month >= 10) {
				a[1] = month / 10;
				a[2] = month % 10;
			} else {
				a[1] = 0;
				a[2] = month;
			}

			// 循环每月的天数
			for (day = 1; day <= months[month]; day++){
				// 将天数存入数组
				if (day >= 10) {
					a[3] = day / 10;
					a[4] = day % 10;
				}
				else {
					a[3] = 0;
					a[4] = day;
				}

				// 由于2022本身不是顺子，且也无法构成顺子，所以仅需判断month于day部分
				// 只有四位需要判断，若第1位到第3位或第2位到第4位为顺子，则此日期为顺子日期
				if (a[2] - a[1] == 1 && a [3] - a[2] == 1
					|| a[4] - a[3] == 1 && a[3] - a[2] == 1) {
					// 输出具体日期
					// for (int i = 1; i < 5; i++) {
					// 	printf("%d", a[i]);
					// }
					// printf("\n");
					// 累加到结果
					sum++;
					}
			}
		}
	}

	printf("%d", sum);

	return 0;
}
