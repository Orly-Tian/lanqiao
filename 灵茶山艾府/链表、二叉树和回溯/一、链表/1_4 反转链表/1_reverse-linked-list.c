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


// 双指针
struct ListNode* reverseList(struct ListNode* head) {
	// current指针遍历链表,pre指向current的前一个节点,也就是反转后current的下一个节点
    struct ListNode *current = head, *pre = NULL;

	while (current) {
		// after指向current的下一个节点
		struct ListNode *after = current->next;

		// 反转当前节点
		current->next = pre;

		// 移动指针
		pre = current;
		current = after;
	}

	// 返回反转后链表的头指针,此时current为NULL,头指针为pre
	return pre;
}
