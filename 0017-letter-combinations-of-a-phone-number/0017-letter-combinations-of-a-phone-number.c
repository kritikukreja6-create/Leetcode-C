/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* phoneMap[] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
void backtrack(char* digits , int index , char* current , char** result , int* returnSize)
{
    if(digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    int digit = digits[index] - '0';
    char* letters = phoneMap[digit];
    for (int i = 0 ; letters[i] != '\0' ; i++) {
        current[index] = letters[i];
        current[index + 1] = '\0';
        backtrack(digits , index + 1 , current , result , returnSize);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    *returnSize = 0;
    if (len == 0) return NULL;
    char** result = (char**)malloc(sizeof(char*) * 300);
    char* current = (char*)malloc(sizeof(char) * (len + 1));
    backtrack(digits , 0 , current , result , returnSize);
    free(current);
    return result;
    
}