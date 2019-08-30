#include<bits/stdc++.h>
using namespace std;

int dp[1501][1501];

int findChoclate(int a,int b)
{
    if(a == 0 && b == 0)
        return 0;
    
    if(dp[a][b] != -1)
        return dp[a][b];
        
    int ans = 0;
    if(a<b)
    {
        int l = b-a;
        int w = a;
        ans = findChoclate(l,w);
    }
    else if(a > b)
    {
        int l = a-b;
        int w = b;
        ans = findChoclate(l,w);
    }
    else
    {
        ans = 1;
    }
    
    dp[a][b] = ans+1;
    return ans+1;
}

int main()
{
    int minl,maxl;
    int minW,maxW;
    cin>>minl>>maxl;
    cin>>minW>>maxW;
    
    memset(dp,-1,sizeof(dp));
    
    int countC = 0;
    for(int i=minl;i<=maxl;i++)
    {
        for(int j=minW;j<=maxW;j++)
        {
            int l = i;
            int w = j;
            int k = findChoclate(l,w)-1;
            countC += k;
        }
    }
    cout<<countC;
    return 0;
}