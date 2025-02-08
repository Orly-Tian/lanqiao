// 530.二叉搜索树的最小绝对差
// Created by Administrator on 2025/2/8.
// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
// https://www.bilibili.com/video/BV1DD4y11779

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

#define MIN(a, b) a < b ? a : b


// 双指针在遍历时直接判断并返回结果
void traversal(struct TreeNode *root,int *pre, int *result) {
	// 二叉搜索树中序遍历为递增序列
	// 其最小绝对差为相邻的两元素之差
	if (root == NULL)
		return;

	traversal(root->left, pre, result);

	// 第一次递归时跳过
	if (*pre != INT_MIN)
		*result = MIN(*result, root->val - *pre);
	// 第一次递归将pre赋值，此后每次递归pre皆为root的前一个val值
	*pre = root->val;

	traversal(root->right, pre, result);

}


int getMinimumDifference(struct TreeNode* root) {
    int pre = INT_MIN, result = INT_MAX;
	traversal(root, &pre, &result);
	return result;
}
