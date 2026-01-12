/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int max_child_depth = 0;

    for (int i = 0; i < root->numChildren ; i++) {
        int current_child_depth = maxDepth(root->children[i]);
        if (current_child_depth > max_child_depth) {
            max_child_depth = current_child_depth;
        }
    }
    return 1 + max_child_depth;
}