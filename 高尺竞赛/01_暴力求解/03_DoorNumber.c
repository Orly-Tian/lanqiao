// 3.门牌制作
// Created by Administrator on 2025/3/2.
// 2020年省赛

#include <stdio.h>


// 在24年7月做过一次，当时思路为利用数学性质来统计2出现的次数，但会有漏掉的情况
// 这次使用暴力穷举
int main() {
	int check(int num);
	int result = 0;

	for (int i = 1; i <= 2020; i++) {
		result += check(i);
	}
	printf("%d", result);

	return 0;
}


int check(int num) {
	int count = 0;

	while (num) {
		int temp = num % 10;
		if (temp == 2)
			count++;
		num /= 10;
	}
	return count;
}

// 事实证明，找对方法很重要



// Python版本
sum = 0
for i in range(1, 2021):
	i = str(i)
	num += i.count("2")
print(num)

