typedef struct Node {
    int key;
    struct Node* next;
} Node;


typedef struct {
    int base;
    Node** buckets;
} MyHashSet;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}
MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->base = 769;
    obj->buckets = (Node**)calloc(obj->base , sizeof(Node*));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int h = key % obj->base;
    Node* curr = obj->buckets[h];
    
    while(curr) {
        if (curr->key == key) return ;
        curr = curr->next;
    }
    Node* newNode  = createNode(key);
    newNode->next = obj->buckets[h];
    obj->buckets[h] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int h = key % obj->base;
    Node* curr = obj->buckets[h];
    Node* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                obj->buckets[h] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int h = key % obj->base;
    Node* curr = obj->buckets[h];
    while(curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for(int i = 0 ; i < obj->base; i++) {
        Node* curr = obj->buckets[i];
        while(curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    } 
    free(obj->buckets);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/