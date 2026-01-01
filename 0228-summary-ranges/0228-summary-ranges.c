/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;

    }
    char** result = (char**)malloc(numsSize * sizeof(char*));
    int count = 0;
    for (int i = 0; i < numsSize ; i++) {
        int start = i;
        while (i +  1 < numsSize && nums[i + 1 ] == nums[i] +  1)
    {
        i++;
    }
    int end = i;
    char* buffer = (char*)malloc(25 * sizeof(char));

    if( start == end) {
        sprintf(buffer , "%d" , nums[start]);

    } else {
        sprintf(buffer , "%d->%d" , nums[start] , nums[end]);

    }
    result[count++] = buffer;
    }

    *returnSize = count;
    return result;
}