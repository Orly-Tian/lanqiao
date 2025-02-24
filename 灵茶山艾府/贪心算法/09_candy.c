// 135.分发糖果
// Created by Administrator on 2025/2/24.
// https://leetcode.cn/problems/candy/
// https://www.bilibili.com/video/BV1ev4y1r7wN

#define max(a, b) (a > b ? a : b)


// 代码随想录
int candy(int *ratings, int ratingsSize) {
	int candy[ratingsSize];
	for (int i = 0; i < ratingsSize; i++)
		candy[i] = 1;

	// 从左向右
	for (int i = 1; i < ratingsSize; i++)
		if (ratings[i] > ratings[i - 1])
			candy[i] = candy[i - 1] + 1;

	// 从右向左
	for (int i = ratingsSize - 2; i >= 0; i--)
		if (ratings[i] > ratings[i + 1])
			candy[i] = max(candy[i], candy[i + 1] + 1);

	int result = 0;
	for (int i = 0; i < ratingsSize; i++)
		result += candy[i];
	return result;
}


// 代码随想录思路做：
//		通过了16/49个测试用例
// int candy(int* ratings, int ratingsSize) {
//     int candy[ratingsSize];
//     candy[0] = 1;
//
//     // 第一次遍历：从左往右
//     for (int i = 1; i < ratingsSize; i++) {
//         if (ratings[i] > ratings[i - 1])
//             candy[i] = candy[i - 1] + 1;
//         else
//             candy[i] = 1;
//     }
//
//     // 第二次遍历：从右往左
//     for (int i = ratingsSize - 2; i > 0; i--) {
//         // &后面的条件为了防止ratings[1, 2, 1]中间的元素2前后遍历加两边
//         if (ratings[i] > ratings[i + 1] && ratings[i] <= ratings[i - 1])
//             // 除外部两次遍历的贪心外，还有一层小贪心
//             // candy[i]此刻值的局部最优解为两次遍历的最大值，这样则为满足条件的最小值
//             candy[i] = max(candy[i + 1] + 1, candy[i]);
//     }
//     // 有了上面的条件后，为了防止第二次遍历时，遍历不到ratings[1, 0, 1]第一个元素
//     if (ratings[0] > ratings[1])
//         candy[0] += 1;
//
//     int total = 0;
//     for (int i = 0; i < ratingsSize; i++)
//         total += candy[i];
//
//     return total;
// }
//
//
// int main() {
//     int ratings[] = {1, 2, 87, 87, 87, 2, 1};
//     int result = candy(ratings, 7);
//     printf("%d", result);
//
//     return 0;
// }
//
