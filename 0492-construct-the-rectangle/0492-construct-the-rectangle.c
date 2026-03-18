/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int w = (int)sqrt(area);
    while(area % w != 0) {
        w--;
    }
    int l = area / w;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = l;
    result[1] = w;
    *returnSize = 2;
    return result;
}