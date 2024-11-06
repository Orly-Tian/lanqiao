// 21.合并两个有序链表
// Created by Administrator on 2024/11/6.
// https://leetcode.cn/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // 判空,若一个链表为空则直接返回另外一个
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    // 创建新链表
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    // 新链表p指针指向头指针
    struct ListNode *p = head;

    // 两链表都非空时
    while (list1 && list2) {
        // 若list1的值小,则将list1的值存放入新链表
        if (list1->val < list2->val) {
            // 新链表的p.next指向此节点
            p->next = list1;
            // list1指针指向下一个节点
            list1 = list1->next;
        }
        // 反之亦然
        else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }

    // 若list1链表仍有值,则将后面链到p.next
    if (list1)
        p->next = list1;
    else if (list2)
        p->next = list2;

    // 返回新链表头指针的next节点
    return head->next;
}


/*  第一次做:(不会,仅有思路)
 *  1.创建新链表,
 *  2.在两链表都有值的条件下遍历两链表,
 *      比较链表的值,将节点值更小的创建新节点链接到新链表
 *  3.若某一链表仍有值,将此链表剩下部分链接到新链表
 *
 *
 *  leetcode官方题解:
 *  方法一:(迭代模拟算法)
 *  1.思路基本相同
 *
 *
 */

