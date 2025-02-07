// 700.二叉搜索树中的搜索
// Created by Administrator on 2025/2/7.
// https://leetcode.cn/problems/search-in-a-binary-search-tree/
// https://www.bilibili.com/video/BV1wG411g7sF

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


struct TreeNode* searchBST(struct TreeNode* root, int val) {
	if (root == NULL || root->val == val)
		return root;

	if (val < root->val)
		return searchBST(root->left, val);
	if (val > root->val)
		return searchBST(root->right, val);

	return NULL;
}
