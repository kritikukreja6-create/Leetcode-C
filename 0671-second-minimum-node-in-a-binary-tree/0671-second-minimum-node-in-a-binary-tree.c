/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 long findNext(struct TreeNode* node , int firstMin) {
    if (node == NULL) return -1;
    if ( node->val > firstMin) {
        return (long)node->val;
    }
    long left = findNext(node->left , firstMin);
    long right = findNext(node->right , firstMin);
    if (left != -1 && right != -1) {
        return (left < right) ? left : right;
    }
    return (left != -1) ? left : right;
 }
int findSecondMinimumValue(struct TreeNode* root) {
    if(root == NULL) return -1;
    long result = findNext(root , root->val);
    return (int)result;
}