int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int res = 0;

    // 1. Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Handle sign
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Convert digits and handle overflow
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        /* * Check for overflow before multiplying by 10.
         * INT_MAX is 2147483647.
         * If res > 214748364, then res * 10 will definitely overflow.
         * If res == 214748364 and the next digit > 7, it will also overflow.
         */
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;
        i++;
    }

    return res * sign;
}