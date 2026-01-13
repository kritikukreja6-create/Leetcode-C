int compare(const void* a , const void* b) { 
    return (*(int*)a - *(int*)b);
}
int distributeCandies(int* candyType, int candyTypeSize) {
    qsort(candyType , candyTypeSize , sizeof(int), compare);

    int uniqueCount = 1;
    for (int i = 1 ; i < candyTypeSize ; i++) {
        if(candyType[i]  != candyType[i - 1]) {
            uniqueCount++;
        }
    }
    int limit = candyTypeSize/2;
    return (uniqueCount < limit) ? uniqueCount : limit;
} 