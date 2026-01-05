int compare(const void *a , const void *b) {
    return (*(int*)a - *(int*)b);
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g , gSize , sizeof(int) , compare);
    qsort(s , sSize , sizeof(int) , compare);

    int child_i = 0;
    int cookie_j = 0;

    while (child_i < gSize && cookie_j < sSize) {
        if(s[cookie_j] >= g[child_i]) {
            child_i++;
        }
        cookie_j++;
    }
    return child_i;
}