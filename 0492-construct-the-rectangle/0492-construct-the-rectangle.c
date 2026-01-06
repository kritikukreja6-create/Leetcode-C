/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    int w = (int)sqrt(area);
    while (area % w != 0) {
        w--;
    }
    int l = area / w;

    result[0] = l;
    result[1] = w;

    return result;
}