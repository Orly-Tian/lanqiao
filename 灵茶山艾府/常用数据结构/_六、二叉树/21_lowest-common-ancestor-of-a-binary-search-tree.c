// 235.二叉搜索树的最近公共祖先
// Created by Administrator on 2025/2/11.
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
// https://www.bilibili.com/video/BV1Zt4y1F7ww

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>


// 精简版：
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

	if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);
	if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);

	return root;
}



// 第一版：
// struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
//     if (root == NULL)
//     	return NULL;
// 	if ((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))
// 		return root;
//
// 	struct TreeNode *result;
// 	if (root->val >= p->val && root->val >= q->val)
// 		result = lowestCommonAncestor(root->left, p, q);
// 	if (root->val <= p->val && root->val <= q->val)
// 		result = lowestCommonAncestor(root->right, p, q);
//
// 	if (result)
// 		return result;
// 	else
// 		return NULL;
// }
