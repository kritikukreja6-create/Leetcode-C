int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int maxLen = 1;
    int currentLen = 1;

    for(int i = 1 ; i < numsSize ; i++)
    {
        if (nums[i] > nums[i - 1])
    { 
     currentLen++; }

     else {
        currentLen = 1;
    }
    if ( currentLen > maxLen) {
        maxLen = currentLen;
    }
 }
 return maxLen;
}
