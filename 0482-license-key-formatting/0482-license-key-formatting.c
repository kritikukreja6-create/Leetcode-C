char* licenseKeyFormatting(char* s, int k) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len * 2 + 1));
    int count = 0;
    int j = 0;

    for ( int i = len - 1; i >= 0; i--) {
        if (s[i] != '-') {
            if (count > 0 && count % k == 0) {
                res[j++] = '-';
            }
            res[j++] = toupper(s[i]);
            count++;
        }
    }
    res[j] = '\0';

    for ( int l = 0 , r = j - 1 ; l < r ; l++ , r--) {
        char temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    return res;
}