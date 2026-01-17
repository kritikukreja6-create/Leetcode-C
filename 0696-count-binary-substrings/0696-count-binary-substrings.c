#define MIN(a,b) ((a) < (b) ? (a) : (b))
int countBinarySubstrings(char* s) {
    int n = strlen(s);
    if ( n <= 1) return 0;
    int total = 0;
    int prevGroupLen = 0;
    int currGroupLen = 1;

    for ( int i = 1; i < n ; i++) {
        if (s[i] == s[i - 1]) {
            currGroupLen++;
        } else {
               total += MIN(prevGroupLen, currGroupLen);
            prevGroupLen = currGroupLen;
            currGroupLen = 1;
        }
    }
    total += MIN(prevGroupLen, currGroupLen);
    return total;
}