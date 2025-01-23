// 101.对称二叉树
// Created by Administrator on 2025/1/22.
// https://leetcode.cn/problems/symmetric-tree/
// 视频讲解:https://www.bilibili.com/video/BV1ue4y1Y7Mf
// leetcode用户题解:https://leetcode.cn/problems/symmetric-tree/solutions/11704/cyu-yan-jian-jian-dan-dan-ji-xing-dai-ma-jie-jue-4/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int compare(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    return (left->val == right->val) && 
            compare(left->left, right->right) &&
            compare(left->right, right->left);
}


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return compare(root->left, root->right);
}
