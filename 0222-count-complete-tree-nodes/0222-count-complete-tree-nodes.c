/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getLeftHeight(struct TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
} 

int countNodes(struct TreeNode* root) { 
    if (!root) return 0;
    int leftH = getLeftHeight(root->left);
    int rightH = getLeftHeight(root->right);
    if (leftH == rightH)
    {
        return (1 << leftH) + countNodes(root->right);

    }else {
        return (1 << rightH) + countNodes(root->left);
    }
    
}