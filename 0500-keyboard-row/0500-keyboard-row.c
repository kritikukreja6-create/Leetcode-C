/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    int rowMap[26];
    char* rows[] = { "qwertyuiop" , "asdfghjkl" , "zxcvbnm"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; rows[i][j] !='\0'; j++) {
            rowMap[rows[i][j] - 'a'] = i + 1;
        }
    }
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;
    for (int i = 0 ; i < wordsSize; i++) {
        char* word = words[i];
        bool isValid = true;
        int firstChar = tolower(word[0]) - 'a';
        int targetRow = rowMap[firstChar];
        for(int j = 1; word[j] != '\0' ; j++) {
            int currentChar = tolower(word[j]) - 'a';
            if (rowMap[currentChar] != targetRow) {
                isValid = false;
                break;
             }
        }
        if (isValid) { 
            result[count] = (char*)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(result[count], word);
            count++;
        }
    }
    *returnSize = count;
    return result;
}