// 225.用队列实现栈
// Created by Administrator on 2025/1/5.
// https://leetcode.cn/problems/implement-stack-using-queues/

#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 100


// Line 56: Char 19: runtime error: index -1 out of bounds for type 'int [100]' [solution.c]

typedef struct {
    int queue[MaxSize];
	int front, rear, size;
} MyStack;


// 创建栈
MyStack* myStackCreate() {
	// 给栈分配空间,且将队头队尾索引初始化为0
	MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
	myStack->front = 0;
	myStack->rear = 0;
	myStack->size = 0;

	return myStack;
}


// 入栈操作:队尾入队,且循环队列
void myStackPush(MyStack* obj, int x) {
// 	// 若队满则返回false
// 	if (obj->rear == obj->front - 1)
// 		return false;

	// 队尾入队
	obj->queue[obj->rear] = x;
	// 队尾++,且循环队列
	obj->rear = (obj->rear + 1) % MaxSize;
	// 队列长度++
	obj->size++;
}


// 出栈操作:即将队列遍历出队入队size-1遍后,将此刻的队头(原本的队尾)元素出队
int myStackPop(MyStack* obj) {
	int front = obj->front;
	int size = obj->size;

	// 遍历队列size-1遍,使队尾元素变为队头
	for (int i = 0; i < size - 1; i++) {
		int popOut = obj->queue[front--];
		myStackPush(obj, popOut);
	}

	// Line 56: Char 19: runtime error: index -1 out of bounds for type 'int [100]' [solution.c]
	// 将此刻的队头元素出队
	return obj->queue[front--], size--;
}


// 返回栈顶元素:即出队队尾,然后将队尾再次入队
int myStackTop(MyStack* obj) {
	// 出队,且保留队尾元素
	int top = myStackPop(obj);
	// 将队尾元素重新入队
	myStackPush(obj, top);

	// 返回队尾元素
	return top;
}


// 判空操作
bool myStackEmpty(MyStack* obj) {
	if (obj->size == 0)
		return true;
	else
		return false;
}

void myStackFree(MyStack* obj) {
	obj->front = 0;
	obj->rear = 0;
	obj->size = 0;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/













// typedef struct {
//
// } MyStack;
//
//
// MyStack* myStackCreate() {
//
// }
//
// void myStackPush(MyStack* obj, int x) {
//
// }
//
// int myStackPop(MyStack* obj) {
//
// }
//
// int myStackTop(MyStack* obj) {
//
// }
//
// bool myStackEmpty(MyStack* obj) {
//
// }
//
// void myStackFree(MyStack* obj) {
//
// }
//
// /**
//  * Your MyStack struct will be instantiated and called as such:
//  * MyStack* obj = myStackCreate();
//  * myStackPush(obj, x);
//
//  * int param_2 = myStackPop(obj);
//
//  * int param_3 = myStackTop(obj);
//
//  * bool param_4 = myStackEmpty(obj);
//
//  * myStackFree(obj);
// */
