int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;

    for (int i = 0 ; i < numsSize ; i++) {
        int current = nums[i];
        if (current == first || current == second ||current == third) {
          continue;
        }
        if (current > first) {
            third = second;
            second = first;
            first = current;
        } else if ( current > second) {
            third = second;
            second = current;
        } else if (current > third) {
            third = current;
        }
    }
    if ( third == LONG_MIN) {
        return (int)first;
    }
    return (int)third;
    
}