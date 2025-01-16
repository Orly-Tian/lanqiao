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



// 94.二叉树的中序遍历
// https://leetcode.cn/problems/binary-tree-inorder-traversal/
void inOrder(struct TreeNode *root, int *result, int *resultSize) {
    if (root == NULL)
        return;
    inOrder(root->left, result, resultSize);
    result[(*resultSize)++] = root->val;
    inOrder(root->right, result, resultSize);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;
    inOrder(root, result, returnSize);
    return result;
}



// 145.二叉树的后序遍历
void postOrder(struct TreeNode *root, int *result, int *resultSize) {
    if (root == NULL)
        return;
    postOrder(root->left, result, resultSize);
    postOrder(root->right, result, resultSize);
    result[(*resultSize)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;
    postOrder(root, result, returnSize);
    return result;
}
