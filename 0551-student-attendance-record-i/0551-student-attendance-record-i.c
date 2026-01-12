bool checkRecord(char* s) {
 int absentCount = 0;
 int n = strlen(s);
 for ( int i = 0; i < n ; i++)
 {
    if(s[i] == 'A') {
        absentCount++;
        if(absentCount >= 2) {
            return false;
        }
    }
    if(s[i] == 'L' && i + 2 < n)  
 {
    if(s[i + 1] == 'L' && s[i + 2] == 'L') {
        return false;
      }
    }
  }
  return true;
}