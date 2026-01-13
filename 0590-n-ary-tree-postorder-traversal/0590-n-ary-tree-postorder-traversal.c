/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void traverse (struct Node* root, int* result , int* returnSize) 
 {
    if(root == NULL) return ;
    for (int i = 0; i < root->numChildren ; i++) {
        traverse(root->children[i] , result , returnSize);
    }
    result[(*returnSize)++] = root->val;
 }
int* postorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* result = (int*)malloc(10000 * sizeof(int));
    traverse(root , result , returnSize);
    return result;
}