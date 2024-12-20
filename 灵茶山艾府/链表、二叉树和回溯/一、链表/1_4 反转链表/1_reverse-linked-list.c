// 206.反转链表
// Created by Administrator on 2024/12/19.
// https://leetcode.cn/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>


// 递归
//		(思路同双指针)
struct ListNode* reverseList(struct ListNode* head) {
	// 声明函数
	struct ListNode* reverse(struct ListNode *head, struct ListNode *pre);

	// 创建遍历链表的current指针与当前的pre指针
	struct ListNode *current = head, *pre = NULL;

	// 递归函数返回结果
	return reverse(current, pre);
}


struct ListNode* reverse(struct ListNode *current, struct ListNode *pre) {
	// 设置基例,当递归到最深处函数时返回最后结果
	// 此时current为NULL,pre为原链表的最后一个节点,即反转链表后的头节点
	if (current == NULL)
		return pre;

	// 设置链条
	// 反转当前节点的方向
	struct ListNode *after = current->next;
	current->next = pre;

	// 递归函数,并把两参数都后移一位
	return reverse(after, current);
}


// 双指针
// struct ListNode* reverseList(struct ListNode* head) {
// 	// current指针遍历链表,pre指向current的前一个节点,也就是反转后current的下一个节点
//     struct ListNode *current = head, *pre = NULL;
//
// 	while (current) {
// 		// after指向current的下一个节点
// 		struct ListNode *after = current->next;
//
// 		// 反转当前节点
// 		current->next = pre;
//
// 		// 移动指针
// 		pre = current;
// 		current = after;
// 	}
//
// 	// 返回反转后链表的头指针,此时current为NULL,头指针为pre
// 	return pre;
// }
//
