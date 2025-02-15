// 108.将有序数组转换为二叉搜索树
// Created by Administrator on 2025/2/15.
// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
// https://www.bilibili.com/video/BV1uR4y1X7qL

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


// 左闭右闭区间
struct TreeNode *traversal(int *nums, int left, int right) {
	// 超过范围
	if (left > right)
		return NULL;

	// 构造root节点
	int mid = (left + right) / 2;
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = nums[mid];

	// 递归构造左子树与右子树
	root->left = traversal(nums, left, mid - 1);
	root->right = traversal(nums, mid + 1, right);

	return root;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	// 左闭右闭区间
	return traversal(nums, 0, numsSize - 1);
}
