// 257.二叉树的所有路径
// Created by Administrator on 2025/1/29.
// https://leetcode.cn/problems/binary-tree-paths/
// 视频讲解:https://www.bilibili.com/video/BV1ZG411G7Dh
// leetcode官方题解:https://leetcode.cn/problems/binary-tree-paths/solutions/400326/er-cha-shu-de-suo-you-lu-jing-by-leetcode-solution/

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

#include <stdlib.h>


void constructPath(struct TreeNode *root, char **paths, int *returnSize, int *stack, int top) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			char *temp = (char *)malloc(1001);
			int len = 0;
			for (int i = 0; i < top; i++)
				len += sprintf(temp + len, "%d->", stack[i]);
			sprintf(temp + len, "%d", root->val);
			paths[(*returnSize)++] = temp;
		}
		else {
			stack[top++] = root->val;
			constructPath(root->left, paths, returnSize, stack, top);
			constructPath(root->right, paths, returnSize, stack, top);
		}
	}
}


char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char **paths = (char **)malloc(1000 * sizeof(char *));
	   *returnSize = 0;
    int stack[1001];
	constructPath(root, paths, returnSize, stack, 0);
    return paths;
}
