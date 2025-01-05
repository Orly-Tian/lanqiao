// 20.有效的括号
// Created by Administrator on 2025/1/5.
// https://leetcode.cn/problems/valid-parentheses/

#include <stdbool.h>
#include <string.h>


// 判断出栈函数
char pairs(char a) {
	if (a == ')') return '(';
	if (a == ']') return '[';
	if (a == '}') return '{';
	return 0;
}


bool isValid(char* s) {
	// 若字符串长度为奇数,则立即返回false
	int n = strlen(s);
	if (n % 2 != 0)
		return false;

	// 创建栈,top指向栈顶的下一个元素
	int stack[n + 1], top = 0;
	for (int i = 0; i < n; i++) {
		// 遍历数组并保存判断出栈函数的返回值
		char ch = pairs(s[i]);
		// 若判断成功
		if (ch) {
			// 若栈空或匹配失败
			if (top == 0 || stack[top - 1] != ch)
				return false;
			// 出栈成功
			top--;
		}
		// 判断失败则入栈
		else
			stack[top++] = s[i];
	}

	// 遍历结束栈空则返回true
	return top == 0;
}

