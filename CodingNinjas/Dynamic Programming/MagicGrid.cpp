#include <bits/stdc++.h>
using namespace std;

int calMinHealth(int **health,int n,int m)
{
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
        dp[i] = new int[m];
    
    
    dp[n-1][m-1] = 1;
    
    // fill the last column
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1] = dp[i+1][m-1]-health[i][m-1];
        if(dp[i][m-1] <= 0)
            dp[i][m-1] = 1;
    }
    
    // fill the last row
    for(int j=m-2;j>=0;j--)
    {
        dp[n-1][j] = dp[n-1][j+1]-health[n-1][j];
        if(dp[n-1][j] <= 0)
            dp[n-1][j] = 1;
    }
    
    // filling rest of the dp matrix
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int c1 = dp[i][j+1];
            int c2 = dp[i+1][j];
            int res = min(c1,c2);
            dp[i][j] = res - health[i][j];
            
            if(dp[i][j] <= 0)
                dp[i][j] = 1;
        }
    }
    
    int result = dp[0][0];
    for(int k=0;k<n;k++)
        delete []dp[k];
    
    return result;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        
        int **health = new int*[r];
        for(int i=0;i<r;i++)
            health[i] = new int[c];
        
        // Input the health array 
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>health[i][j];
        }
        
        
        int result = calMinHealth(health,r,c);
        cout<<result<<endl;
    }
    
    return 0;
}

