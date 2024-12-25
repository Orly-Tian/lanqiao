// 142.环形链表2
// Created by Administrator on 2024/12/24.
// https://leetcode.cn/problems/linked-list-cycle-ii/
// https://www.bilibili.com/video/BV1if4y1d7ob?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>


struct ListNode *detectCycle(struct ListNode *head) {
    // 定义快慢指针
	struct ListNode *fast = head, *slow = head;

	// 移动指针
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		// 若指针相遇
		if (fast == slow) {
			// 此时相遇点据环的起点与链表头据环的起点相等
			struct ListNode *index1 = fast, *index2 = head;
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1;
		}
	}

	return NULL;
}
