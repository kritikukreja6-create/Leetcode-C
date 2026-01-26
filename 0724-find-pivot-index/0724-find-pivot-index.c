int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    int leftSum = 0;
    
    for (int i = 0 ; i < numsSize ; i++) {
        totalSum += nums[i];
    }
    for (int i = 0 ; i < numsSize ; i++) {
        if (leftSum * 2 == totalSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
  return -1;
}