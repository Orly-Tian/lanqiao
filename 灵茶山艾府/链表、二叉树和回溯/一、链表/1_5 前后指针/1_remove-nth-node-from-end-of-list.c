// 19.删除链表的倒数第N个节点
// Created by Administrator on 2024/12/23.
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
// https://www.bilibili.com/video/BV1vW4y1U7Gf?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	// 虚拟头节点
	struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	// 快慢指针
	struct ListNode *fast = dummyHead, *slow = dummyHead;

	// 快指针领先慢指针 n+1 个节点
	for (int i = 0; i <= n; i++)
		fast = fast->next;

	// 循环至快指针到NULL
	while (fast) {
		fast = fast->next;
		slow = slow->next;
    }

	// 此时慢指针位置即所要删除的前一个节点
	slow->next = slow->next->next;

	// 返回首元节点
	return dummyHead->next;
}
