int firstUniqChar(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    for(int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    for ( int i = 0; i < n ; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}