int strStr(char* haystack, char* needle) { 
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen > hLen)
    {
        return -1;

    }
    for (int i = 0; i <= hLen - nLen ; i++)
{
 if (strncmp(&haystack[i] , needle , nLen) == 0)
 {
    return i;
 }
}
    return -1;
}