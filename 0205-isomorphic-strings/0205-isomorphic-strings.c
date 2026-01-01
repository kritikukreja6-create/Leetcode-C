bool isIsomorphic(char* s, char* t) {
    int mapS[256] = {0};
    int mapT[256] = {0};

    int n = strlen(s);

    for(int i = 0 ; i < n ; i++)
    {
        char charS = s[i];
        char charT = t[i];

        if (mapS[charS] != 0 && mapS[charS] != charT) {
            return false;
        }
        if (mapT[charT] != 0 && mapT[charT] != charS){
            return false;
        }
        mapS[charS] = charT;
        mapT[charT] = charS;

    }
    return true;
}