/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(const void* a , const void* b) {
    return (*(int*)a - *(int*)b);
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums , numsSize , sizeof(int) ,compare);
    int capacity = 1024;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnSize = 0;
    for (int i = 0; i < numsSize - 2; i++) 
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right ) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res , capacity * sizeof(int*));

                }
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnSize)++;
                while (left < right && nums[left] == nums[left + 1])left++;
                while (left < right && nums[right] == nums[right - 1])right--;
                left++;
                right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }

        }
    }
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for(int i = 0 ; i < *returnSize ; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}