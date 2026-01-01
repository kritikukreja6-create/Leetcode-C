


typedef struct {
    int *stkIn;
    int *stkOut;
    int topIn;
    int topOut;
    int capacity;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100;
    obj->stkIn  = (int*)malloc(sizeof(int)* obj->capacity);
    obj->stkOut = (int*)malloc(sizeof(int)* obj->capacity);
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
    
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stkIn[++(obj->topIn)] = x;
    
}
void fillOutStack(MyQueue* obj) {
    if (obj->topOut == -1){
        while (obj->topIn != -1){
        obj->stkOut[++(obj->topOut)] = obj->stkIn[(obj->topIn)--];
        }
    }
}
int myQueuePop(MyQueue* obj) {
    fillOutStack(obj);
    return obj->stkOut[(obj->topOut)--];
    
}

int myQueuePeek(MyQueue* obj) {
    fillOutStack(obj);
    return obj->stkOut[obj->topOut];
    
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->topIn == -1 && obj->topOut == -1);
    
}

void myQueueFree(MyQueue* obj) {
    free(obj->stkIn);
    free(obj->stkOut);
    free(obj);
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/