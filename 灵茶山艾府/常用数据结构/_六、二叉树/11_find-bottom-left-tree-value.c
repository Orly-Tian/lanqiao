// 513.找树左下角的值
// Created by Administrator on 2025/2/1.
// https://leetcode.cn/problems/find-bottom-left-tree-value/
// https://www.bilibili.com/video/BV1424y1Z7pn

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


#include <limits.h>
#include <stdio.h>


void traversal(struct TreeNode *root, int depth, int *maxDepth, int *result) {
	if (root->left == NULL && root->right == NULL)
		if (depth > *maxDepth) {
			*maxDepth = depth;
			*result = root->val;
		}
	if (root->left) {
		// 简便写法:
		// traversal(root->left, depth + 1, maxDepth, result);
		depth++;
		traversal(root->left, depth, maxDepth, result);
		// 回溯
		depth--;
	}
	if (root->right) {
		// 简便写法:
		// traversal(root->right, depth + 1, maxDepth, result);
		depth++;
		traversal(root->right, depth, maxDepth, result);
		// 回溯
		depth--;
	}
}


int findBottomLeftValue(struct TreeNode* root) {
	int depth = 1, maxDepth = INT_MIN;
	int result;
	traversal(root, depth, &maxDepth, &result);
	return result;
}


