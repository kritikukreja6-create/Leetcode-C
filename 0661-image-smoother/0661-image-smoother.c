/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize;
    int n = imgColSize[0];
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    int** res = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m ; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    for ( int r = 0 ; r < m; r++) {
        for(int c = 0 ; c < n ; c++) {
            int sum = 0; 
            int count = 0;

            for(int i = r - 1; i <= r + 1; i++) {
                for(int j = c - 1; j <= c + 1 ; j++) {
                    if ( i >= 0 && i < m && j >= 0 && j < n) {
                        sum += img[i][j];
                        count++;
                    }
                }
            }
            res[r][c] = sum /count;
        }
    }
    return res;
    
}