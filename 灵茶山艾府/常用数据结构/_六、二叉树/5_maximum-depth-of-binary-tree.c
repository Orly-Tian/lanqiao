/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int max = left > right ? left : right;
    return max + 1;
}
