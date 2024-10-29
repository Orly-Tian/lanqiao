//
// Created by Administrator on 2024/10/28.
// https://leetcode.cn/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    // 创建结果头指针尾指针
    struct ListNode *head = NULL, *tail = NULL;

    // 初始化进位为0
    int carry = 0;

    // 遍历链表l1与l2
    while (l1 || l2) {
        // 若较短的链表遍历完则将链表数据域视为0
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        // 提取出来的值求和并加上进位
        int sum = n1 + n2 + carry;

        // 若结果链表此时为NULL
        if (!head) {
            // 为结果链表新建一个节点
            head = tail = malloc(sizeof(struct ListNode));
            // 新节点值为求和值的个位数
            tail->val = sum % 10;
            // 尾节点的指针域为NULL
            tail->next = NULL;
        }
        // 若结果链表此时有值
        else {
            // 尾插法插入新节点
            tail->next = malloc(sizeof(struct ListNode));
            // 新节点值为求和值的个位数
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        // 更新进位
        carry = sum / 10;

        // 循环计数器
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    // 若两链表皆遍历结束后仍有进位
    if (carry > 0) {
        // 则先将进位值赋值给新节点
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }

    return head;
}


/*  第一次做：
 *  1.新建结果链表的头节点,并分配节点
 *  2.不会....
 *
 *
 *  leetcode官方题解:
 *  1.新建结果链表的头尾节点
 *  2.初始化进位
 *    遍历两数组,
 *      若链表有值,将链表值提取出来
 *      若链表无值,则视为0
 *
 *      若结果链表无节点,
 *          则分配新节点,值为提取出来的两值加进位
 *      若结果链表有节点,
 *          则尾插法分配新节点,值为提取出来的两值加进位
 *      更新进位
 *      循环计数器
 *  3.若循环结束仍有进位,
 *      则新建节点保存进位制
 *
 */

