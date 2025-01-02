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
	obj->stackIn[obj->stackInTop++] = x;
}


// 出队:先将[入栈]出栈至[出栈],再将[出栈]中已经倒转的元素出栈
//		应复制一个[入栈]出栈,因为若[入栈]出栈至空栈则不能再继续进行正常的入栈出栈操作
int myQueuePop(MyQueue* obj) {
	while (obj->stackInTop) {
		obj->stackOut[obj->stackOutTop++] = obj->stackIn[obj->stackInTop--];
	}

	return obj->stackOut[obj->stackOutTop--];
}


int myQueuePeek(MyQueue* obj) {

}


bool myQueueEmpty(MyQueue* obj) {

}


void myQueueFree(MyQueue* obj) {

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

