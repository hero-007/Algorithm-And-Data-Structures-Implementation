#include <bits/stdc++.h>
using namespace std;

int findMax(int *arr,int left,int right,int flag,int **dp)
{
    if(left > right)
        return 0;
    
    if(dp[left][right] != -1)
        return dp[left][right];
    
    int result;
    if(flag%2 == 1)
    {
        // It is player's turn
        int op1 = arr[left]+findMax(arr,left+1,right,flag+1,dp);
        int op2 = arr[right]+findMax(arr,left,right-1,flag+1,dp);
        int sl = max(op1,op2);
        result = sl;
    }
    else
    {
        // It is opponent's term
        int op1 = findMax(arr,left+1,right,flag+1,dp);
        int op2 = findMax(arr,left,right-1,flag+1,dp);
        int sl = min(op1,op2);
        result = sl;
    }
    
    dp[left][right] = result;
    return result;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    int **dp = new int*[n];
	    for(int i=0;i<n;i++)
	    {
	        dp[i] = new int[n];
	        for(int j=0;j<n;j++)
	            dp[i][j] = -1;
	    }
	    int op = findMax(arr,0,n-1,1,dp);
	    cout<<op<<endl;
	    
	    for(int i=0;i<n;i++)
	        delete []dp[i];
	}
	return 0;
}
