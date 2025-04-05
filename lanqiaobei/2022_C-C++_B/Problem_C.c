// C.刷题统计
// Created by Administrator on 2025/4/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	long long a, b, target;
	long result = 0;
	scanf("%lld %lld %lld", &a, &b, &target);

	// 先除法整除掉满勤的周数
	long long week_target = a * 5 + b * 2;
	result = 7 * (target / week_target);
	target = target % week_target;

	// 将最后未满的一周单独处理
	long long day[7] = {a, a, a, a, a, b, b};
	int i = 0;
	while (target > 0) {
		target -= day[i++];
		result++;
	}

	printf("%lld", result);

	return 0;
}


// 暴力枚举
//		通过了6/10个(60%)测试用例
// int main() {
// 	long long a, b, n;
// 	long long result = 0;
// 	scanf("%lld %lld %lld", &a, &b, &n);
//
// 	while (n > 0) {
//		/*
//		 * 思路：先整除处理掉极大值，再在下面处理小一些的值
//		 *		通过了9/10个(90%)个测试用例
//		 * target的最大值为1e18，这种方法建立在通过测试通过数判断测试用例的规模，不可取
//		*/
//		// if (target >= 100000000 * 5 * a + 100000000 * 2 * b) {
//		// 	target -= 100000000 * 5 * a + 100000000 * 2 * b;
//		// 	result += 700000000;
//		// }
//
// 		// 工作日
// 		if (n > 5 * a) {
// 			n = n - 5 * a; result += 5;
// 		}
// 		else {
// 			while (n > 0) {
// 				n -= a; result++;
// 			}
// 		}
//
// 		// 周末
// 		if (n > 2 * b) {
// 			n = n - 2 * b; result += 2;
// 		}
// 		else {
// 			while (n > 0) {
// 				n -= b; result++;
// 			}
// 		}
// 	}
//
// 	printf("%lld", result);
//
// 	return 0;
// }
//
