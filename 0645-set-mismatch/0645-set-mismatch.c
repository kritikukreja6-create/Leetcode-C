/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int i = 0;
    while( i  < numsSize) {
        int correctIndex = nums[i] - 1; 
        if (nums[i] != nums[correctIndex]) {
            int temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;
        } else {
            i++;
        }
    }
    for ( int j = 0 ; j < numsSize ; j++ ) {
        if (nums[j] != j + 1) {
            result[0] = nums[j];
            result[1] = j + 1;

            break;
        }
    }
    return result;
}