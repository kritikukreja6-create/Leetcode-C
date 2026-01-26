/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool isSelfDividing(int num) {
    int temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0 || num % digit != 0) {
            return false;
        }
        temp /= 10;
    }
    return true;
 }

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int maxRange = right - left + 1;
    int* result = (int*)malloc(maxRange * sizeof(int));
    int count = 0;
    
    for (int i = left ; i < right ; i++) {
        if(isSelfDividing(i)) {
            result[count++] = i;
        }
    }
    *returnSize = count;
    return result;
}