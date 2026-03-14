/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;
    if(numsSize == 0) return result;
    for( int i = 0 ; i < numsSize ; i++) {
        int start = i;
        while( i + 1 < numsSize && (long long)nums[i + 1] == (long long)nums[i] + 1)
    {
        i++;
    }
    char* temp = (char*)malloc(25 * sizeof(char));
    if(start == i ) {
        sprintf(temp , "%d" , nums[start]);
    } else {
        sprintf(temp , "%d->%d" , nums[start] , nums[i]);
    }
    result[(*returnSize)++] = temp;
    }
    return result;
}