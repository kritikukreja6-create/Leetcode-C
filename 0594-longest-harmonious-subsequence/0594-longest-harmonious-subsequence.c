int compare(const void* a , const void* b) {
    return (*(int*)a - *(int*)b);
}
int findLHS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums , numsSize , sizeof(int) , compare);
    int left = 0 , right = 0;
    int maxLen = 0;

    while (right < numsSize) {
        while(nums[right]  - nums[left]  > 1)  {
            left++;
        }
        if (nums[right] - nums[left] == 1) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) maxLen = currentLen;
        }
        right++;
    }
    return maxLen;
}