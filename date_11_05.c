// 20.有效的括号
// Created by Administrator on 2024/11/5.
// https://leetcode.cn/problems/valid-parentheses/description/

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
    int n = strlen(s);
    // 若字符串长度为奇数，则返回false
    if (n % 2 == 1)
        return false;

    // 创建栈，top指向栈顶的下一个元素
    int stack[n+1], top = 0;
    for (int i = 0; i < n; i++) {
        // 遍历原数组并保存判断出栈函数返回值
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
        else {
            stack[top++] = s[i];
        }
    }

    // 遍历结束栈空则返回true
    return top == 0;
}


/*  第一次做:
 *  1.(用栈)不会....
 *
 *
 *  leetcode官方题解:
 *  1.创建栈(数组+top指针),
 *  2.遍历原数组,保留判断出栈函数结果
 *  3.结果若满足出栈条件,
 *      若栈空或匹配失败,返回false
 *    若不满足出栈条件
 *      则入栈
 *  4.若遍历结束后栈空,则返回true
 *
 */
