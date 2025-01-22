// 226.翻转二叉树
// Created by Administrator on 2025/1/22.
// https://leetcode.cn/problems/invert-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    // swap(root->left, root->right)
    struct TreeNode *tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;
    invertTree(root->left);
    invertTree(root->right);

    return root;
}
