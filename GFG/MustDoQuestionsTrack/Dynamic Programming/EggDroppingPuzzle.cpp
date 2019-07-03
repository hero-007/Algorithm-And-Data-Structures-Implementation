#include <bits/stdc++.h>
using namespace std;

int eggDrop(int egg,int level,int **dp)
{
    if(level == 0 || level == 1) 
        return level;
    
    if(egg == 1)
        return level;
    
    if(egg == 0)
        return 0;
    
    if(dp[egg][level] != -1)
        return dp[egg][level];
        
    int ans = INT_MAX;
    for(int i=1;i<=level;i++)
    {
        int maxTryFromThisLevel = 1 + max(eggDrop(egg-1,i-1,dp),eggDrop(egg,level-i,dp));
        ans = min(ans,maxTryFromThisLevel);
    }
    
    dp[egg][level] = ans;
    return ans;
}

int main() {
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    
	    int **dp = new int*[n+1];
	
    	for(int i=0;i<=n;i++)
    	{
    	    dp[i] = new int[k+1];
    	    for(int j=0;j<=k;j++)
    	        dp[i][j] = -1;
    	}
    	
	    int ans = eggDrop(n,k,dp);
	    cout<<ans<<endl;
	    
	    for(int j=0;j<=n;j++)
	        delete []dp[j];
	}
	
	return 0;
}
