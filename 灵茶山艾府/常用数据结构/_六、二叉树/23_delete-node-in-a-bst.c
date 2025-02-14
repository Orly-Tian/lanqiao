// 450.删除二叉搜索树中的节点
// Created by Administrator on 2025/2/13.
// https://leetcode.cn/problems/delete-node-in-a-bst/
// https://www.bilibili.com/video/BV1tP41177us

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


struct TreeNode* deleteNode(struct TreeNode* root, int key) {
	// 未找到所删除节点
    if (root == NULL)
    	return NULL;

	// 找到所删除节点
	if (root->val == key) {
		// 叶子节点
		if (!root->left && !root->right)
			return NULL;
		// 左不空右空
		if (root->left && !root->right)
			return root->left;
		// 右不空左空
		if (!root->left && root->right)
			return root->right;

		// 左右都不为空
		if (root->left && root->right) {
			// 找到root的下一个节点，即右子树的最左节点
			struct TreeNode *current = root->right;
			while (current->left)
				current = current->left;
			// root的左子树链接到右子树的最小节点的左孩子
			current->left = root->left;
			// 返回被删除节点的右子树
			return root->right;
		}
	}

	if (key < root->val)
		root->left = deleteNode(root->left, key);
	if (key > root->val)
		root->right = deleteNode(root->right, key);

	return root;
}
