void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroIndex = 0;

    for(int cur = 0; cur < numsSize ; cur++) {
        if ( nums[cur] != 0) {
            int temp = nums[lastNonZeroIndex];
            nums[lastNonZeroIndex] = nums[cur];
            nums[cur] = temp;
            lastNonZeroIndex++;
        }
    }
    
}