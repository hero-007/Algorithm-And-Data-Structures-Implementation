int knapsack(int* weights, int* values, int n, int maxWeight){
    
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[maxWeight+1];
    }
    
    // Initialize row - 0 and column - 0 with all zeroes
    for(int i=0;i<=maxWeight;i++)
    {
        dp[0][i] = 0;
    }
    
    for(int j=0;j<=n;j++)
    {
        dp[j][0] = 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            int exc_item = dp[i-1][j];
            int inc_item = 0;
            if(weights[i-1] <= j)
                inc_item  = values[i-1] + dp[i-1][j - weights[i-1]];
            
            dp[i][j] = max(exc_item,inc_item);
        }
    }
    
    int res = dp[n][maxWeight];
    for(int i=0;i<=n;i++)
        delete []dp[i];
    
    return res;
}
