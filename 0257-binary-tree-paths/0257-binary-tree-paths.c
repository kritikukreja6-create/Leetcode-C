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
 void dfs(struct TreeNode* node , char* path , char** results, int* returnSize) {
    if(!node) return;
    char currentPath[2000];
    strcpy(currentPath , path);

    char valStr[12];
    sprintf(valStr , "%d" , node->val);
    strcat(currentPath , valStr);

    if (!node->left && !node->right) {
        results[*returnSize] = malloc(strlen(currentPath) + 1);
        strcpy(results[(*returnSize)++] , currentPath);
    } else {
        strcat(currentPath , "->");
        dfs(node->left , currentPath , results , returnSize);
        dfs(node->right , currentPath , results , returnSize);
    }

 }
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(!root) return NULL;

    char** results = malloc(sizeof(char*) * 100 );
    char path[2000] = "";
    dfs(root , path , results , returnSize );
    return results;
}