/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int score;
    int index;
}Athlete;

int compare(const void* a , const void* b) {
    return ((Athlete*)b)->score - ((Athlete*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    Athlete* athletes = (Athlete*)malloc(scoreSize * sizeof(Athlete));
    char** result = (char**)malloc(scoreSize * sizeof(char*));
for ( int i = 0; i < scoreSize; i++) {
    athletes[i].score = score[i];
    athletes[i].index = i;
}
qsort(athletes, scoreSize, sizeof(Athlete) , compare);

for(int i = 0 ; i < scoreSize ; i++) {
    char* rank = (char*)malloc(15 *sizeof(char));
if (i == 0) strcpy(rank , "Gold Medal");
else if (i == 1) strcpy(rank , "Silver Medal");
else if (i == 2) strcpy(rank , "Bronze Medal");
else sprintf(rank , "%d" , i + 1);

result[athletes[i].index] = rank;
}

free(athletes);
return result;
}