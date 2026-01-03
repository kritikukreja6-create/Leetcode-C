/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** answer = (char**)malloc(n * sizeof(char*));
    *returnSize = n;

    for (int i = 1 ; i <= n; i++) {
        answer[i - 1] = (char*)malloc(10 * sizeof(char));

        if (i % 3 == 0 && i % 5 == 0) {
            sprintf(answer[ i - 1] , "FizzBuzz");
        } else if ( i % 3 == 0) {
            sprintf(answer[ i - 1] , "Fizz");
        } else if ( i % 5 == 0) {
            sprintf(answer[ i - 1] , "Buzz");
        }else {
            sprintf(answer[i - 1] , "%d" , i);
        }
    }
    return answer;
}