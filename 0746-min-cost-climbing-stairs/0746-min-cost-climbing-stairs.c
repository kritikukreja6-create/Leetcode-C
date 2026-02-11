#define MIN(a,b) ((a) < (b) ? (a) : (b))
int minCostClimbingStairs(int* cost, int costSize) {
    int first = cost[0];
    int second = cost[1];
    
    for(int i = 2 ; i < costSize ; i++) {
        int current = cost[i] + MIN(first , second);
        first = second;
        second = current;
    }
    return MIN(first , second);
    
}