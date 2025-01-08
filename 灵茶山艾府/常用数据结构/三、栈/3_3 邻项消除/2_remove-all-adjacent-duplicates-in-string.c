// 1047.删除字符串中的所有相邻重复项
// Created by Administrator on 2025/1/8.
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
// https://www.bilibili.com/video/BV12a411P7mw/?spm_id_from=333.337.search-card.all.click&vd_source=4c293aa27f67a76d01553a3b9517eaf3

#include <stdlib.h>
#include <string.h>


char* removeDuplicates(char* s) {
	// 创建字符串模拟栈,并分配空间
	char *stack = (char *)malloc(strlen(s) * sizeof(char));
	int stackTop = 0;

	// 遍历原字符串
	for (int i = 0; i < strlen(s); i++) {
		// 若栈非空且串元素与栈顶元素匹配
		if (stackTop > 0 && stack[stackTop - 1] == s[i])
			// 则出栈,且下一个元素继续遍历
			stackTop--;

		// 若栈空或串元素与栈顶元素不匹配,则串元素进栈
		else
			stack[stackTop++] = s[i];
	}

	// 栈的最后一个字符置'\0'
	stack[stackTop] = '\0';

	// 返回栈
	return stack;
}

