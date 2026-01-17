#define MAX_VAL 50000
int findShortestSubArray(int* nums, int numsSize) {
    int count[MAX_VAL] = {0};
    int first[MAX_VAL];
    int last[MAX_VAL];
    
    memset(first , -1 , sizeof(first));
    int degree = 0;
    for(int  i = 0 ; i < numsSize ; i++) {
        int x = nums[i];
        if (first[x]  == -1) {
            first[x] = i;
        }
        last[x] = i;
        count[x]++;
        if (count[x] > degree) {
            degree = count[x];
        }
    }
    int minLen = numsSize;
    for(int i = 0; i < numsSize ; i++) {
        int x = nums[i];
        if(count[x] == degree) {
            int currentLen = last[x] - first[x] + 1;
            if (currentLen < minLen) {
                minLen = currentLen;
            }
        }
    }
    return minLen;
}