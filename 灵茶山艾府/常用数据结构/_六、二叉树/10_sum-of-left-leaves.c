// 404.左叶子之和
// Created by Administrator on 2025/1/30.
// https://leetcode.cn/problems/sum-of-left-leaves/
// https://www.bilibili.com/video/BV1GY4y1K7z8

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


int sumOfLeftLeaves(struct TreeNode* root) {
	// 空节点
    if (root == NULL)
    	return 0;
	// 叶子节点
	if (root->left == NULL && root->right == NULL)
		return 0;

	// 递归取左子树和右子树的左叶子之和
	int leftNum = sumOfLeftLeaves(root->left);
	int rightNum = sumOfLeftLeaves(root->right);

	// 若符合左叶子条件,则赋值
	if (root->left && root->left->left == NULL && root->left->right == NULL)
		leftNum = root->left->val;

	// 将累计值传出
	int sum = leftNum + rightNum;
	return sum;
}
