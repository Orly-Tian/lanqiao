// 144.二叉树的层序遍历
// Created by Administrator on 2025/1/14.
// https://leetcode.cn/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** ans = (int **)malloc(2000 * sizeof(int *));
    *returnSize = 0;
    if (!root)
        return NULL;
    int columnSizes[2000];
    struct TreeNode *queue[2000];
    int head = 0, rear = 0;
    queue[rear++] = root;

    while (rear != head) {
        ans[(*returnSize)] = (int *)malloc((rear - head) * sizeof(int));
        columnSizes[(*returnSize)] = rear - head;
        int start = head;
        head = rear;
        for (int i = start; i < head; i++) {
            ans[(*returnSize)][i - start] = queue[i]->val;
            if (queue[i]->left)
                queue[rear++] = queue[i]->left;
            if (queue[i]->right)
                queue[rear++] = queue[i]->right;
        }
        (*returnSize)++;
    }

    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = columnSizes[i];
    return ans;
}
