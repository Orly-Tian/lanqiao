// 24.两两交换链表中的节点
// Created by Administrator on 2024/12/21.
// https://leetcode.cn/problems/swap-nodes-in-pairs/
// https://www.bilibili.com/video/BV1YT411g7br?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>


struct ListNode* swapPairs(struct ListNode* head) {
	// 虚拟头节点
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	// 遍历链表的current指针
	// 因需要反转两个节点,所以须将current指向这两个节点的前一个节点,且遍历步长为2
	struct ListNode *current = dummyHead;

	// 循环条件为current的后两个节点都不为NULL
	// 若链表长度为奇数,则最后一个节点不去进行任何操作
	while (current->next && current->next->next) {
		// 创建两个temp指针临时存放节点地址
		struct ListNode *temp = current->next;
		struct ListNode *nextTemp = current->next->next->next;
		// 交换节点位置
		current->next = current->next->next;
		current->next->next = temp;
		current->next->next->next = nextTemp;
		// 移动current指针,步长为2
		current = current->next->next;
	}

	// 返回首元节点
	return dummyHead->next;
}

