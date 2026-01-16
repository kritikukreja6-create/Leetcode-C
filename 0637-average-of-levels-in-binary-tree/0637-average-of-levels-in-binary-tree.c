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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
   if (root == NULL) {
    *returnSize = 0;
    return NULL;
   } 
   double* averages = (double*)malloc(10000 * sizeof(double));
   struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
   int head = 0 , tail = 0;
   int levelCount = 0;

   queue[tail++] = root;

   while (head < tail) {
    int nodesAtLevel = tail - head;
    double levelSum = 0;

    for( int i = 0 ; i < nodesAtLevel ; i++) {
        struct TreeNode* currentNode = queue[head++];
        levelSum += currentNode->val;
        if (currentNode->left) {
            queue[tail++] = currentNode->left;
        }
        if (currentNode->right) {
             queue[tail++]  = currentNode->right;
            
        }
    }
        averages[levelCount++] = levelSum / nodesAtLevel;
    }
    *returnSize = levelCount;
    free(queue);
    return averages;

   }
