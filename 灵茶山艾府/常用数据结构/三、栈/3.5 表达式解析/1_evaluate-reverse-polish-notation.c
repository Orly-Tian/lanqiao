// 150.逆波兰表达式求值
// Created by Administrator on 2025/1/9.
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
// https://www.bilibili.com/video/BV1kd4y1o7on


#include <stdio.h>

// https://www.cnblogs.com/ZY-Dream/p/10038503.html
int evalRPN(char** tokens, int tokensSize) {
	int stack[tokensSize], stackTop = 0;
	for (int i = 0; i < tokensSize; i++) {
		char *token = tokens[i];
		if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
			int num1 = stack[--stackTop];
			int num2 = stack[--stackTop];
			stack[stackTop++] = num1 + num2;
		}
		else {
			stack[stackTop++] = *token;
		}
	}

	return stack[--stackTop];
}


int main() {
	char token[13] = {"10", '6','9','3','+',"-11",'*','/','*',"17",'+','5','+'};
	int result = evalRPN(&&token, 13);
}
