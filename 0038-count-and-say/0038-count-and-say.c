char* countAndSay(int n) {
    if (n <= 0) return NULL;
    char* res = malloc(10000 * sizeof (char));
    strcpy(res , "1");
    char* temp = malloc (10000 * sizeof(char));
     
    for ( int i = 1 ; i < n ; i++) {
        int res_len = strlen(res);
        int temp_idx = 0;

        for (int j = 0 ; j < res_len ; j++) {
            int count = 1;
            while (j + 1 < res_len && res[j] == res[j + 1]) {
                count++;
                j++;
            }
            temp_idx += sprintf(&temp[temp_idx] , "%d%c" ,count , res[j] );
        }
        strcpy(res , temp);
    }
    free(temp);
    return res;
}