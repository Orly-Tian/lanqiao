// 654.最大二叉树
// Created by Administrator on 2025/2/6.
// https://leetcode.cn/problems/maximum-binary-tree/
// https://www.bilibili.com/video/BV1MG411G7ox

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


// 查找最大值
int maxNum(int *nums, int numsSize) {
	int i = 0, max = i;
    for (; i < numsSize; i++) {
	    if (nums[i] > nums[max])
	    	max = i;
    }
	return max;
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
	// 数组为空则返回NULL
	// 若不加numsSize判断，则堆溢出，因为下面递归将使用numsSize决定数组大小
    if (nums == NULL || numsSize == 0)
    	return NULL;

	// 查找最大值为根节点
	int index = maxNum(nums, numsSize);
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = nums[index];

	// 递归查找并分配左子树与右子树的根节点
	root->left = constructMaximumBinaryTree(nums, index);
	root->right = constructMaximumBinaryTree(nums + index + 1, numsSize - index - 1);

	return root;
}

