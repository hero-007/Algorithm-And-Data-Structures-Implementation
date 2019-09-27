/**

Chef has a sequence A1,A2,…,AN. This sequence has exactly 2N subsequences. 
Chef considers a subsequence of A interesting if its size is exactly K and the sum of all its elements is minimum possible, i.e. there is no subsequence with size K which has a smaller sum.

Help Chef find the number of interesting subsequences of the sequence A.


**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll find_count(int arr[],int n,int k,int min_sum,int pos,ll ***dp)
{
	if(k == 0 && min_sum == 0)
		return 1;
	
	if(k == 0 || pos == n)
		return 0;
		
	if(dp[pos][min_sum][k] != -1)
		return dp[pos][min_sum][k];
	
		
	ll res = 0;
	if(arr[pos] > min_sum)
		res = find_count(arr,n,k,min_sum,pos+1,dp);
	else
		res = find_count(arr,n,k,min_sum,pos+1,dp)+find_count(arr,n,k-1,min_sum-arr[pos],pos+1,dp);
		
	dp[pos][min_sum][k] = res;
	return res;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		
		for(int i=0;i<n;i++) 
			cin>>arr[i];
		
		sort(arr,arr+n);
		
		
		int min_sum = 0;
		for(int i=0;i<k;i++)
			min_sum += arr[i];
		
		ll ***dp = new ll**[n+1];
		for(int i=0;i<=n;i++)
		{
			dp[i] = new ll*[min_sum+1];
			for(int j=0;j<=min_sum;j++)
			{
				dp[i][j] = new ll[k+1];
				for(int y=0;y<=k;y++)
					dp[i][j][y] = -1;
			}
		}
		
		ll count = 0;
		
		count = find_count(arr,n,k,min_sum,0,dp);
		cout<<count<<endl;
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=min_sum;j++)
			{
				delete []dp[i][j];
			}
		}
	}
	
	return 0;
}
