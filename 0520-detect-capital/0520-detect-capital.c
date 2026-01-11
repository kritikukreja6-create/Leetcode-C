bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int upperCount = 0;

    for (int i = 0; i < len ; i++) {
        if(isupper(word[i])) {
            upperCount++;
        }
    }
    if (upperCount == len) {
        return true;
    }
    if (upperCount == 0) {
        return true;
    }
    if(upperCount == 1 && isupper(word[0])){
        return true;
    }
    return false;
}