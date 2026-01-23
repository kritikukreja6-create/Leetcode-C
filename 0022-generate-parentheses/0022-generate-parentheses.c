/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char** result , int* returnSize, char* current , int open , int close , int n  )  {
    if(strlen(current) == 2 * n) {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    if (open < n) {
        int len = strlen(current);
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result , returnSize , current , open + 1 , close , n);
        current[len] = '\0';
    }
    if (close < open) {
        int len = strlen(current);
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result , returnSize , current , open ,close + 1 , n );
        current[len] = '\0';
    } 

}
char** generateParenthesis(int n, int* returnSize) {
    char** result = (char**)malloc(5000 * sizeof(char*));
    *returnSize = 0;

    char* current = (char*)calloc(2 *  n + 1 , sizeof(char));
    backtrack(result , returnSize , current , 0 , 0 , n);
    free(current);
    return result;
}