/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void dfs(int** image , int row , int col , int rows , int cols , int oldColor , int newColor) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != oldColor) {
        return;
    }
    image[row][col] = newColor;
    dfs(image , row + 1 , col , rows , cols , oldColor , newColor);
    dfs(image , row - 1 , col , rows , cols , oldColor , newColor);
    dfs(image , row , col + 1 , rows , cols , oldColor , newColor);
    dfs(image , row , col - 1 , rows , cols , oldColor , newColor);
 }

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
 int oldColor = image[sr][sc];
  if (oldColor != color) {
    dfs(image , sr, sc , imageSize , imageColSize[0] , oldColor , color);
  }
  *returnSize = imageSize;
  *returnColumnSizes = imageColSize;
  return image;
}