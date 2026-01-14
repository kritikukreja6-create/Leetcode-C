bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if ( n <= 0) return true;
    for(int i = 0; i < flowerbedSize ; i++) {
        if(flowerbed[i] == 0) {
            bool leftEntry = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightEntry = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);
            if (leftEntry && rightEntry) {
                flowerbed[i] = 1;
                n--;
                if (n <= 0) {
                    return true;
                }
            }
        }
    }
    return n <= 0;
}