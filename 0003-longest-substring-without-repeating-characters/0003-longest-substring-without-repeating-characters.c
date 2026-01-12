int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    int count[128] = {0};
    int left = 0 , right = 0;
    int maxLen = 0;

    while (right < n) {
        char r = s[right];
        count[r]++;
        
        while (count[r] > 1) {
            char l = s[left];
            count[l]--;
            left++;
        }
        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
          right++;

    }
    return maxLen;

}