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
 int maxCount;
 int currentCount;
 int currentVal;
 int modeCount;

 void handleValue(int val , int* result , int pass) {
    if (val == currentVal) {
        currentCount++;
    } else {
        currentVal = val;
        currentCount = 1;
    }

    if (pass == 1) {
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    } else {
        if (currentCount == maxCount) {
            if (result != NULL) {
            result[modeCount] = val;
            }
        modeCount++;
       }
    }
 }
void inOrder(struct TreeNode* root, int* result , int pass) {
    if (root == NULL) return;
    inOrder(root->left , result , pass);
    handleValue(root->val , result , pass);
    inOrder(root->right , result , pass);
 }
int* findMode(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0 ;
        return NULL;
    }
    maxCount = 0;
    currentCount = 0;
    currentVal = 0;
    modeCount = 0;

    inOrder(root , NULL , 1);
    currentCount = 0;
    currentVal = 0;
    int tempModeCount = 0;

    inOrder(root , NULL, 2);
    int* result = (int*)malloc(modeCount * sizeof(int));

    modeCount = 0;
    currentCount = 0;
    currentVal = 0;
    inOrder(root , result , 2);

    *returnSize = modeCount;
    return result;
}