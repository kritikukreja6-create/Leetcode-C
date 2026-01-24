int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    long long l_dividend = llabs((long long) dividend);
    long long l_divisor = llabs((long long) divisor);
    long long quotient = 0;

    while (l_dividend >= l_divisor) {
        long long temp = l_divisor;
        long long multiple = 1;

        while (l_dividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        l_dividend -= temp;
        quotient += multiple;
    }
    return (int)(sign * quotient);
}