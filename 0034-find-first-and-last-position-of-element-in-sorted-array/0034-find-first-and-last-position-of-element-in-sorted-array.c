/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int findBound(int* nums, int numsSize , int target , int isFirst) {
    int left = 0 , right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            bound = mid;
            if (isFirst) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return bound;
 }


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
 *returnSize = 2;
 int* result = (int*)malloc(2 * sizeof(int));
 result[0] = findBound(nums , numsSize , target, 1);
 result[1] = findBound(nums , numsSize , target, 0);
 return result;
}