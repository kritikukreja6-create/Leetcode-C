typedef struct Node {
    int val;
    int last_index;
    struct Node* next;
} Node;

#define HASH_SIZE 10007

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    Node** table = (Node**)calloc(HASH_SIZE , sizeof(Node*));
    bool found = false;

    for(int i = 0 ; i < numsSize ; i++) {
        unsigned int key = abs(nums[i]) % HASH_SIZE;
        Node* curr = table[key];

        while (curr) {
            if (curr->val == nums[i]) {
                if(i - curr->last_index <= k) {
                    found = true;
                    goto cleanup;
                }
                curr->last_index = i;
                goto next_element;
            }
            curr = curr->next;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->last_index = i;
        newNode->next = table[key];
        table[key] = newNode;

        next_element:;
    }
    cleanup:
    for (int i = 0 ; i < HASH_SIZE ; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table);
    return found;
}