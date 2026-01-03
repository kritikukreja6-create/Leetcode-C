/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int sumHelper(struct TreeNode* node , bool isLeft) {
    if (node == NULL) {
        return 0;
    }
    if ( node->left == NULL && node->right == NULL) {
        return isLeft ? node->val : 0;
    }
    return sumHelper(node->left , true) + sumHelper(node->right, false);
 }
int sumOfLeftLeaves(struct TreeNode* root) {
    return sumHelper(root , false);
}