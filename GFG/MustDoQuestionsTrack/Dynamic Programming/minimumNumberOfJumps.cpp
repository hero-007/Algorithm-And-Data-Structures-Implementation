#include <bits/stdc++.h>
using namespace std;

int findMinSteps(int *arr,int n,int pos,int *dp)
{
    if(pos >= n-1)
        return 0;
    
    if(arr[pos] == 0)
        return -1;
    
    if(dp[pos] != -1)
        return dp[pos];
        
    int min_step = INT_MAX;
    int k = arr[pos];
    bool dead = false;
    
    for(int i=1;i<=k;i++)
    {
        int res = findMinSteps(arr,n,pos+i,dp);
        
        if(res == -1)
        {
            dead = true;
            continue;
        }
        
        if(res < min_step)
            min_step = res;
    }
    
    if(min_step == INT_MAX)
        min_step = -1;
        
    if(min_step == -1)
        dp[pos] = -1;
    else
        dp[pos] = min_step+1;
        
    return dp[pos];
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int *arr = new int[n];
	    int *dp = new int[n];
	  
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        dp[i] = -1;
	    }
	        
	    int res = findMinSteps(arr,n,0,dp);
	    cout<<res<<endl;
	    
	    delete []arr;
	}
	
	return 0;
}
