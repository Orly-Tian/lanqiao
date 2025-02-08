// 98.验证二叉搜索树
// Created by Administrator on 2025/2/8.
// https://leetcode.cn/problems/validate-binary-search-tree/

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


// 代码随想录题解：
//		通过了83/86个测试用例，测试用例中有[-2147483648,-2147483648]
bool traversal(struct TreeNode *root, int *pre) {
    if (root == NULL)
    	return true;

	bool left = traversal(root->left, pre);

	if (*pre != INT_MIN && *pre >= root->val)
		return false;
	*pre = root->val;

	bool right = traversal(root->right, pre);

	return left && right;
}


bool isValidBST(struct TreeNode* root) {
	int pre = NULL;
	return traversal(root, &pre);
}



// 第一版：
//		使用先序遍历，通过77/86个测试用例
//		仅检查当前节点与左右孩子节点的关系，没有按照二叉搜索树定义(中序遍历结果严格递增)的要求
// bool isValidBST(struct TreeNode* root) {
// 	if (root == NULL)
// 		return true;
//
// 	bool result = true;
//
// 	// 判断左孩子是否合法
// 	if (root->left && root->left->val >= root->val)
// 		result = false;
// 	// 判断右孩子是否合法
// 	if (root->right && root->right->val <= root->val)
// 		result = false;
//
// 	if (result)
// 		result = isValidBST(root->left);
// 	if (result)
// 		result = isValidBST(root->right);
//
// 	return result;
// }
//

