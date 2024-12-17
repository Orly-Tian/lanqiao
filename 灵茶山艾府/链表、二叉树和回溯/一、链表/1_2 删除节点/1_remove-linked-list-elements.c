// 203.移除链表元素
// Created by Administrator on 2024/12/16.
// https://leetcode.cn/problems/remove-linked-list-elements/
// https://www.bilibili.com/video/BV18B4y1s7R9/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=4c293aa27f67a76d01553a3b9517eaf3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>


// 使用头节点
struct ListNode* removeElements(struct ListNode* head, int val) {
	// 创建头节点
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;

	// 通过头节点统一遍历规则
	struct ListNode *current = dummyHead;
	// 若current节点的下一个节点存在
	while (current->next) {
		// 存在且为目标值,则删除节点
		// 且并不后移，因为下次循环判断的下一个节点仍未判断
		if (current->next->val == val)
			current->next = current->next->next;

		// 若不是目标值,则后移一位
		else
			current = current->next;
	}

	// 为防止首元节点即为目标值,则返回头节点的next节点
	return dummyHead->next;
}



// 不使用头节点
// 移除头节点和其他节点的操作不统一，因为移除其他节点皆是通过被移除节点的上一个节点来进行操作
// 移除头节点的方式为直接向后移位
// 注:不释放内存的空间复杂度更低
// struct ListNode* removeElements(struct ListNode* head, int val) {
//     struct ListNode *temp;
//
// 	// 当首元节点为目标值时
// 	while (head && head->val == val) {
// 		// 将目标值放入temp指针
// 		temp = head;
// 		head = head->next;
// 		// 释放目标值节点
// 		free(temp);
// 	}
//
// 	struct ListNode *current = head;
// 	// 遍历链表
// 	while (current && current->next) {
// 		// 若current下一个节点为目标值
// 		if (current->next->val == val) {
// 			temp = current->next;
// 			// 删除下一个节点,且并不后移，因为下次循环判断的下一个节点仍未判断
// 			current->next = current->next->next;
// 			// 释放目标值节点
// 			free(temp);
// 		}
//
// 		else
// 			// 否则current节点后移一位
// 			current = current->next;
// 	}
//
// 	return head;
// }
//
