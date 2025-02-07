// 617.合并二叉树
// Created by Administrator on 2025/2/7.
// https://leetcode.cn/problems/merge-two-binary-trees/
// https://www.bilibili.com/video/BV1m14y1Y7JK

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


// leetcode官方题解：
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL)
    	return root2;
	if (root2 == NULL)
		return root1;

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = root1->val + root2->val;

	root->left = mergeTrees(root1->left, root2->left);
	root->right = mergeTrees(root1->right, root2->right);

	return root;
}



/*
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL)
    	return NULL;

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	if (root1 && root2)
		root->val = root1->val + root2->val;
	else if (root1)
		root->val = root1->val;
	else if (root2)
		root->val = root2->val;

	// 版本1：空指针内成员访问
	// if (root1->left || root2->left)
	// 	root->left = mergeTrees(root1->left, root2->left);
	// if (root1->right || root2->right)
	// 	root->right = mergeTrees(root1->right, root2->right);

	// 版本2：空指针内成员访问
	root->left = mergeTrees(
		(root1->left ? root1->left : NULL),
		(root2->left ? root2->left : NULL)
		);
	root->right = mergeTrees(
		(root1->right ? root1->right : NULL),
		(root2->right ? root2->right : NULL)
		);

	return root;
}
*/

