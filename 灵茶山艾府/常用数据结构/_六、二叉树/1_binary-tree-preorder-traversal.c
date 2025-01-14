// 144.二叉树的前序遍历
// Created by Administrator on 2025/1/14.
// https://leetcode.cn/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void preOrder(struct TreeNode *root, int *ret, int *returnSize) {
    if (root == NULL)
        return;
    ret[(*returnSize)++] = root->val;
    preOrder(root->left, ret, returnSize);
    preOrder(root->right, ret, returnSize);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}
