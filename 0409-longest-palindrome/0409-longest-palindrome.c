int longestPalindrome(char* s) {
    int count[128] = {0};
    int length = 0;
    int hasOdd = 0;
    int n = strlen(s);

    for(int i = 0; i < n ; i++)
    {
        count[(int)s[i]]++;
    }
    for (int i = 0; i < 128 ; i++) {
        length += (count[i] / 2) * 2;

        if (count[i] % 2 != 0) {
            hasOdd = 1;
        }
    }
    if (hasOdd) {
        length += 1;
    }
    return length;
}