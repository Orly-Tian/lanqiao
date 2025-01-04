// 232.用栈实现队列
// Created by Administrator on 2025/1/2.
// https://leetcode.cn/problems/implement-queue-using-stacks/
// https://www.bilibili.com/video/BV1nY4y1w7VC?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3

#include <stdbool.h>
#include <stdlib.h>


// 一个[入栈]一个[出栈],两栈结合模拟队列
typedef struct {
	int stackIn[100], stackOut[100];
	int stackInTop, stackOutTop;
} MyQueue;


// 分配空间给新队列
MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue *)malloc(sizeof(MyQueue));
	queue->stackInTop = 0;
	queue->stackOutTop = 0;

	return queue;
}


// 入队:即为入栈至[入栈]
void myQueuePush(MyQueue* obj, int x) {
	// top-1才为栈顶元素的索引值
	obj->stackIn[obj->stackInTop++] = x;
}


// 出队:先将[入栈]出栈至[出栈],再将[出栈]中已经倒转的元素出栈
//		(应复制一个[入栈]出栈,因为若[入栈]出栈至空栈则不能再继续进行正常的入栈出栈操作)
//		将[入栈]出栈至[出栈]后,再将[出栈]全部出栈至[入栈]
int myQueuePop(MyQueue* obj) {
	// 优化:复制栈顶指针,减少对结构体的访问次数
	int stackInTop = obj->stackInTop;
	int stackOutTop = obj->stackOutTop;

	// 若[出栈]为空,则[入栈]的全部元素出栈至[出栈]
	if (stackOutTop == 0)
		while (stackInTop)
			obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];

	// 将[出栈]的栈顶元素出栈,并保存
	int top = obj->stackOut[--stackOutTop];

	// 将[出栈]中元素重新返回至[入栈]
	while (stackOutTop > 0)
		obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];

	// 更新两栈的栈顶指针
	obj->stackInTop = stackInTop;
	obj->stackOutTop = stackOutTop;

	return top;
}


// 返回队头元素:即将[入栈]出栈至[出栈],返回[出栈]的队头元素
int myQueuePeek(MyQueue* obj) {
	/*	方法一:
	 *		直接使用myQueuePop()函数出栈,取得队头元素并保存
	 *		再用myQueuePush()函数将队头元素入栈
	 *		返回所保存的队头元素
	 */

	// 方法二:
	//		将myQueuePop()函数重写一边,但是只返回元素并不出栈
	// 优化:复制栈顶指针,减少对结构体的访问次数
	int stackInTop = obj->stackInTop;
	int stackOutTop = obj->stackOutTop;

	// 若[出栈]为空,则[入栈]的全部元素出栈至[出栈]
	if (stackOutTop == 0)
		while (stackInTop)
			obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];

	// 返回[出栈]的栈顶元素,不出栈
	int top = obj->stackOut[stackOutTop - 1];

	// [出栈]全部元素返回至[入栈]
	while (stackOutTop > 0)
		obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];

	obj->stackInTop = stackInTop;
	obj->stackOutTop = stackOutTop;

	return top;
}


// 队列的判空操作:若两栈的元素都为空,则队空
bool myQueueEmpty(MyQueue* obj) {
	return obj->stackInTop == 0 && obj->stackOutTop == 0;
}


// 释放队列:将两栈指针置零
void myQueueFree(MyQueue* obj) {
	obj->stackInTop = 0;
	obj->stackOutTop = 0;
}


/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/














//
// typedef struct {
//
// } MyQueue;
//
//
// MyQueue* myQueueCreate() {
//
// }
//
// void myQueuePush(MyQueue* obj, int x) {
//
// }
//
// int myQueuePop(MyQueue* obj) {
//
// }
//
// int myQueuePeek(MyQueue* obj) {
//
// }
//
// bool myQueueEmpty(MyQueue* obj) {
//
// }
//
// void myQueueFree(MyQueue* obj) {
//
// }
//
// /**
//  * Your MyQueue struct will be instantiated and called as such:
//  * MyQueue* obj = myQueueCreate();
//  * myQueuePush(obj, x);
//
//  * int param_2 = myQueuePop(obj);
//
//  * int param_3 = myQueuePeek(obj);
//
//  * bool param_4 = myQueueEmpty(obj);
//
//  * myQueueFree(obj);
// */
//
//
