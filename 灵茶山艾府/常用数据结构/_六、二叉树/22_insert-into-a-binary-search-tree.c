// 701.二叉搜索树中的插入操作
// Created by Administrator on 2025/2/12.
// https://leetcode.cn/problems/insert-into-a-binary-search-tree/
// https://www.bilibili.com/video/BV1Et4y1c78Y

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>


// 第二版：代码随想录题解
//		递归外返回处理指针链接
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
	    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    	node->val = val;
    	node->left = NULL;
    	node->right = NULL;
    	return node;
    }

	if (val < root->val)
		root->left = insertIntoBST(root->left, val);
	if (val > root->val)
		root->right = insertIntoBST(root->right, val);

	return root;
}



// 第一版：
//		边界条件处理指针链接
// struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
// 	if (!root) {
// 		root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
// 		root->val = val;
// 		// 若未处理指针指向NULL，则报错地址错位
// 		// runtime error: member access within misaligned address 0xbebebebebebebebe for type 'struct TreeNode', which requires 8 byte alignment [TreeNode.c]
// 		root->left = NULL;
// 		root->right = NULL;
// 	}
// 	if (!root->left && val < root->val) {
// 		root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
// 		root->left->val = val;
// 		root->left->left = NULL;
// 		root->left->right = NULL;
// 	}
// 	if (!root->right && val > root->val) {
// 		root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
// 		root->right->val = val;
// 		root->right->left = NULL;
// 		root->right->right = NULL;
// 	}
//
// 	if (val < root->val)
// 		insertIntoBST(root->left, val);
// 	if (val > root->val)
// 		insertIntoBST(root->right, val);
//
// 	return root;
// }
//
