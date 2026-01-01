typedef struct {
    int value;
    int index;
    bool occupied;
}HashEntry;
int getHash(int key , int size) {
    int h = key % size;
    return (h < 0) ? h + size : h;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize <= 1 ) return false;

    int size = numsSize * 2;
    HashEntry* table = calloc(size , sizeof(HashEntry));
    for( int i = 0 ; i < numsSize ; i++) {
        int h = getHash(nums[i] , size);

        while ( table[h].occupied) {
            if( table[h].value == nums[i])
            {
                if (i - table[h].index <= k) {
                    free(table);
                    return true;
                }
                table[h].index = i;
                goto next_num;

            }
            h = (h + 1) % size;
        }
        table[h].value = nums[i];
        table[h].index = i;
        table[h].occupied = true;
        next_num:;
    }
    free(table);
    return false;
}