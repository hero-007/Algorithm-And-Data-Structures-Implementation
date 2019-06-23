
int findMaxValue(int *weights,int *values,int n,int maxWeight,int **dp)
{
    // base cases
    if(maxWeight == 0)
        return 0;
    
    if(n == 0)
        return 0;
    
    if(dp[n][maxWeight] != -1)
        return dp[n][maxWeight];
    
    int res;
    if(weights[n-1] > maxWeight)
        res = findMaxValue(weights,values,n-1,maxWeight,dp);
    else
    {
        int incl_item = values[n-1] + findMaxValue(weights,values,n-1,maxWeight - weights[n-1],dp);
        int exc_item = findMaxValue(weights,values,n-1,maxWeight,dp);
        
        res = max(incl_item,exc_item);
    }
    
    dp[n][maxWeight] = res;
    return res;
}
