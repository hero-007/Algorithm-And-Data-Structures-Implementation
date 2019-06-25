#include <bits/stdc++.h>
using namespace std;

bool findSubset(int *arr,int n,int sum)
{
    bool **dp = new bool*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new bool[sum+1];
    }
    
    // initialize first row with all false except 0,0
    for(int i=0;i<=sum;i++)
        dp[0][i] = false;
    
    // initialize first column with all true
    for(int j=0;j<=n;j++)
            dp[j][0] = true;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j] = dp[i-1][j];
            
            if(arr[i-1] <= j)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
    
    bool res = dp[n][sum];
    
    for(int i=0;i<=n;i++)
            delete []dp[i];
    
    return res;
}

int main()
{
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int sum;
    cin>>sum;
    
    bool result = findSubset(arr,n,sum);
    if(result)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    return 0;
}

