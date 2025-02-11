// 236.二叉树的最近公共祖先
// Created by Administrator on 2025/2/9.
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// https://www.bilibili.com/video/BV1jd4y1B7E2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


struct TreeNode* traversal(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root == NULL)
    	return NULL;

	if (root == p || root == q)
		return root;

	struct TreeNode *left = traversal(root->left, p, q);
	struct TreeNode *right = traversal(root->right, p, q);

	if (left && right)
		return root;
	if (left && !right)
		return left;
	if (!left && right)
		return right;

	return NULL;
}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    return traversal(root, p, q);
}
