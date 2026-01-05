char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;

    int maxLen = (i > j ? i : j) + 2;
    char* res = (char*)malloc((maxLen + 1) * sizeof(char));
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? num1[i--] - '0' : 0;
        int d2 = (j >= 0) ? num2[j--] - '0' : 0;
         
        int sum = d1 + d2 + carry;
        res[k++] = (sum % 10) + '0';
        carry = sum/10;

    }
    res[k] = '\0';

    for (int left = 0 , right = k - 1; left < right; left++ ,right--) {
        char temp = res[left];
        res[left] = res[right];
        res[right] = temp;

    }
    return res;

}