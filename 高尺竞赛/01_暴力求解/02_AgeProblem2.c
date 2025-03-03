// 2.猜年龄
// Created by Administrator on 2025/3/2.
//

#include <stdio.h>


int main() {
	for (int i = 1; i < 30; i++) {
		for (int j = i + 1; j <= i + 8; j++) {
			if ((i * j) == (i + j) * 6)
				printf("%d", i);
		}
	}
}
