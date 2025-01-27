// 110.平衡二叉树
// Created by Administrator on 2025/1/27.
// https://leetcode.cn/problems/balanced-binary-tree/
// https://www.bilibili.com/video/BV1Ug411S7my

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


int getHeight(struct TreeNode* root) {
	// 递归函数的基例
	if (root == NULL)
		return 0;

	// 遍历左子树
	int left = getHeight(root->left);
	if (left == -1)
		return -1;
	// 遍历右子树
	int right = getHeight(root->right);
	if (right == -1)
		return -1;

	// 处理根节点
	if (abs(left - right) > 1)
		return -1;
	else {
		return fmax(left, right) + 1;
	}
}


bool isBalanced(struct TreeNode* root) {
	int result = getHeight(root);
	if (result == -1)
		return false;
	else
		return true;
}

