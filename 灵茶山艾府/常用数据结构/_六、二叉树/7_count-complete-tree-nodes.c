/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// 方法二:使用满二叉树性质
int countNodes(struct TreeNode* root) {
    // 终止条件1
    if (root == NULL)
        return 0;

    // 终止条件2
    // 使用满二叉树的性质
    struct TreeNode *left = root->left, *right = root->right;
    int leftDepth = 0, rightDepth = 0;
    while (left) {
        left = left->left;
        leftDepth++;
    }
    while (right) {
        right = right->right;
        rightDepth++;
    }
    if (leftDepth == rightDepth)
        return (2 << leftDepth) - 1;

    // 递归函数的链条
    int leftNum = countNodes(root->left);
    int rightNum = countNodes(root->right);
    return leftNum + rightNum + 1;
}


// 方法一:遍历二叉树
void postOrder(struct TreeNode *root, int *count) {
    if (root == NULL)
        return;
    postOrder(root->left, count);
    postOrder(root->right, count);
    (*count)++;
}


int countNodes(struct TreeNode* root) {
    int count = 0;
    postOrder(root, &count);
    return count;
}
