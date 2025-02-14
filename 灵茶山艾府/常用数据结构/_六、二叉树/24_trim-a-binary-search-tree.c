// 669.修剪二叉搜索树
// Created by Administrator on 2025/2/14.
// https://leetcode.cn/problems/trim-a-binary-search-tree/
// https://www.bilibili.com/video/BV17P41177ud

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (root == NULL)
    	return NULL;
	// 若root节点小于low
	if (root->val < low) {
		// 但root节点的右子树有可能有节点大于low
		return trimBST(root->right, low, high);
	}
	// 若root节点大于high
	if (root->val > high) {
		// 但root节点的左子树有可能有节点小于high
		return trimBST(root->left, low, high);
	}

	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);

	return root;
}
