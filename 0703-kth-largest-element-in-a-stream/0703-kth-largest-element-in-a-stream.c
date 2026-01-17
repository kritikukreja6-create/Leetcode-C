


typedef struct {
    int* heap;
    int size;
    int capacity;
} KthLargest;

void swap(int* a , int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int* heap , int size , int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    
    if (smallest != i) {
        swap(&heap[i] , &heap[smallest]);
        minHeapify(heap , size , smallest);
    }
}

void bubbleUp(int* heap , int i) {
    while(i > 0 && heap[( i - 1) / 2] > heap[i]) {
        swap(&heap[i] , &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        bubbleUp(obj->heap , obj->size);
        obj->size++;
    } else if( val > obj->heap[0]) {
        obj->heap[0] = val;
        minHeapify(obj->heap , obj->size , 0);
    }
    return obj->heap[0];
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    for (int i = 0 ; i < numsSize ; i++) {
        kthLargestAdd(obj , nums[i]);
    }
    return obj;
}

 

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/