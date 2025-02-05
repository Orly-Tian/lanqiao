// 106.从中序与后序遍历序列构造二叉树
// Created by Administrator on 2025/2/3.
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// https://www.bilibili.com/video/BV1vW4y1i7dn

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


// 寻找分割点
int linearSearch(int *arr, int arrSize, int key) {
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == key)
			return i;
	return -1;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0)
    	return NULL;

	// 根节点为后序遍历的最后一个元素
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = postorder[postorderSize - 1];

	// 通过线性查找函数找到分割点
	int index = linearSearch(inorder, inorderSize, postorder[postorderSize - 1]);

	// 递归分隔中序和后序求左右子树
	// 中序左子树为[0, index)，右子树为[index + 1, orderSize)
	// 后序左子树为[0, index)，右子树为[index, orderSize - 1)	右子树等长
	root->left = buildTree(inorder, index, postorder, index);
	root->right = buildTree(inorder + index + 1, inorderSize - index - 1,
							postorder + index, postorderSize - index - 1);

	return root;
}
