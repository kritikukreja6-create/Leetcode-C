/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calculateHeight(struct TreeNode* node , int * diameter) {
    if(node == NULL) return 0;
    int leftHeight = calculateHeight(node->left ,diameter);
    int rightHeight = calculateHeight(node->right , diameter);
    if(leftHeight + rightHeight > *diameter)
    {
        *diameter = leftHeight + rightHeight;
    }
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    calculateHeight(root , &diameter);
    return diameter;
}