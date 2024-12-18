// 707.设计链表
// Created by Administrator on 2024/12/17.
// https://leetcode.cn/problems/design-linked-list/

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

#include <stdlib.h>

// 未完成(第69行Error)
typedef struct Node {
	int val;
	struct Node *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
	MyLinkedList *head;
	MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	head = Node;

	return head;
}


int myLinkedListGet(MyLinkedList* obj, int index) {
	int count = 0;

	if (index < 0)
		return -1;

	MyLinkedList *p = obj;
	while (p && count <= index) {
		if (count == index) {
			return p->val;
		}
		else {
			p = p->next;
			count++;
		}
	}
	return -1;
}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	p->val = val;
	p->next = obj->next;
	obj->next = p;
}


void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	MyLinkedList *tail = obj;
	while (tail->next) {
		tail = tail->next;
	}
	// ERROR:
	// Line 69: Char 13: runtime error: member access within misaligned address 0xbebebebebebebebe for type 'struct MyLinkedList', which requires 8 byte alignment [solution.c]
	// 0xbebebebebebebebe: note: pointer points here
	// <memory cannot be printed>

	MyLinkedList *p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	p->val = val;
	tail->next = p;
}


void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	int count = 0;
	MyLinkedList *p = obj;
	MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));

	if (index == 0) {
		node->val = val;
		node->next = p->next;
		p->next = node;
	}

	while (p || count < index) {
		if (count == index - 1) {
			node->val = val;
			node->next = p->next;
			p->next = node;
		}
		else {
			p = p->next;
			count++;
		}
	}
}


void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	int count = 0;
	MyLinkedList *p = obj;
	MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));

	if (index == 0)
		obj = obj->next;

	while (p || count < index) {
		if (count == index - 1) {
			p->next = p->next->next;
		}
		else {
			p = p->next;
			count++;
		}
	}

}


void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList *before = obj, *after = obj;
	while (before || after) {
		if (before) {
			after = before->next;
			free(before);
		}
		else {
			before = after->next;
			free(after);
		}
	}

}


