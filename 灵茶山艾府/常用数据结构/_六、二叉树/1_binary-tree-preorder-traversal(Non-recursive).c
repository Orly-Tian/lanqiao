// 144.二叉树的前序遍历(非递归)
// Created by Administrator on 2025/1/14.
// https://leetcode.cn/problems/binary-tree-preorder-traversal/


// 中序遍历(未完成)
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


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *current = root;
    struct TreeNode *stack = (struct TreeNode*)malloc(100 * sizeof(struct TreeNode));
    int stackTop = 0;
    int result[100];
    *returnSize = 0;
    while (stackTop || current) {
        if (current) {
            stack[stackTop++] = *current;
            current = current->left;
        }
        else {
            struct TreeNode temp = stack[--stackTop];
            result[(*returnSize)++] = temp.val;
            current = temp.right;
        }
    }

    return result;
}
