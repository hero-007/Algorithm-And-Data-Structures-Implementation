#include<bits/stdc++.h>
using namespace std;
#define limit 100001

int findMax(int n,int *dp)
{
	if(n == 0 || n == 1)
		return 0;
	
	if(n == 2)
		return 1;
	
	if(dp[n] != -1)
		return dp[n];
		
	int a = findMax(n/2,dp);
	int b = findMax(n/3,dp);
	int c = findMax(n/4,dp);
	
	int res = a+b+c;
	
	if(n > res)
		res = n;
	
	dp[n] = res;
	return res;
}

int main()
{
	int t;
	cin>>t;
	
	int *dp = new int[limit];
	for(int i=0;i<limit;i++)
		dp[i] = -1;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
		
	while(t--)
	{
		int n;
		cin>>n;
		int result = findMax(n,dp);
		cout<<result<<endl;
		
	}
	
	delete []dp;
	return 0;
}
