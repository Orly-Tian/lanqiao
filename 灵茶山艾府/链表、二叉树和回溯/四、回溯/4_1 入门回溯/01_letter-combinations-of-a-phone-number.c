// 17.电话号码的字母组合
// Created by Administrator on 2025/3/17.
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
// https://www.bilibili.com/video/BV1yV4y1V7Ug

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>


// 建立数字与字母的映射
char *letterMap[10] = {
	"", "", "abc", "def",
	"ghi", "jkl", "mno",
	"pqrs", "tuv", "wxyz",
};

// 符合条件的单个结果
char *str;
// 符合条件的所有结果
char **result;
int strTop, resultTop;


// digits为输入的数字字符串
// index为当前遍历到的数字字符
void backtracking(char *digits, int index) {
	// 若index遍历完整个数字字符串
	if (index == strlen(digits)) {
		// 深拷贝当前结果至结果字符串
		char *temp = (char *)malloc((strlen(digits) + 1) * sizeof(char));
		for (int i = 0; i < strlen(digits); i++)
			temp[i] = str[i];
		temp[strlen(digits)] = 0;
		result[resultTop++] = temp;
		return;
	}

	// 将数字字符转换为整型
	int digit = digits[index] - '0';
	// 提取出映射库中的对应整型的字符串
	char *letters = letterMap[digit];
	for (int i = 0; i < strlen(letters); i++) {
		// 将当前遍历元素加入至结果字符串
		str[strTop++] = letters[i];
		backtracking(digits, index + 1);
		// 回溯，元素出栈
		strTop--;
	}
}


char** letterCombinations(char* digits, int* returnSize) {
	// 分配内存并初始化栈
    str = (char *)malloc(strlen(digits) * sizeof(char));
	result = (char **)malloc(300 * sizeof(char *));
	strTop = resultTop = 0;

	*returnSize = 0;
	// 若digits中元素个数为0，则返回空集
	if (!strlen(digits))
		return result;

	backtracking(digits, 0);

	*returnSize = resultTop;

	return result;
}
