/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int calculateSubtreeSum(struct TreeNode* node , int* totalTilt) {
    if (node == NULL) return 0;
    int leftSum = calculateSubtreeSum(node->left , totalTilt);
    int rightSum = calculateSubtreeSum(node->right , totalTilt);
    int currentTilt = abs(leftSum - rightSum);
    *totalTilt += currentTilt;
    return node->val + leftSum + rightSum;
 }
int findTilt(struct TreeNode* root) {
    int totalTilt = 0;
    calculateSubtreeSum(root , &totalTilt);
    return totalTilt;
}