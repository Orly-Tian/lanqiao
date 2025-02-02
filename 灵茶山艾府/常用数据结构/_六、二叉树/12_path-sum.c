// 112.路径总和
// Created by Administrator on 2025/2/2.
// https://leetcode.cn/problems/path-sum/
// https://www.bilibili.com/video/BV19t4y1L7CR

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


bool traversal(struct TreeNode *root, int count) {
	if (root == NULL)
		return false;

	if (root->left == NULL && root->right == NULL ) {
		if (count - root->val == 0)
			return true;
		else
			return false;
	}

	if (root->left)
		if (traversal(root->left, count - root->val))
			return true;
	if (root->right)
		if (traversal(root->right, count - root->val))
			return true;

	return false;
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
	if (traversal(root, targetSum))
		return true;
	return false;
}
