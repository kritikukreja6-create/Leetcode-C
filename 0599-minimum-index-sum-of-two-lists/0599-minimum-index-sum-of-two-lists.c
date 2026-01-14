/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int minSum = INT_MAX;
    char** result = (char**)malloc(sizeof(char*) * (list1Size < list2Size ? list1Size : list2Size ));
    int count = 0;
    for(int i = 0; i < list1Size ; i++) {
        if ( i > minSum) break;
        for ( int j = 0 ; j < list2Size ; j++) {
            if ( i + j > minSum) break;

            if (strcmp(list1[i] , list2[j]) == 0) {
                int  currentSum =  i + j;
                if (currentSum < minSum) {
                    minSum = currentSum;
                    count = 0;
                    result[count++]  = list1[i];
                } else if (currentSum == minSum) {
                    result[count++] = list1[i];
                }
            }
        }
    }
    *returnSize = count;
    return result;
}