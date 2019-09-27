#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long 

int main()
{
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	
	unordered_map<int,int> umap;	// stores the count of each element
	
	for(int i=0;i<n;i++) 
	{
		int a;
		cin>>a;
		umap[a]++;
		arr[i] = a;
	}
	
	vector<int> temp;	// stores the elements 
	
	unordered_set<int> t;
	for(int i=0;i<n;i++)
	{
		if(t.find(arr[i]) == t.end())
		{
			temp.push_back(arr[i]);
			t.insert(arr[i]);
		}
	}
	
	int l = temp.size() - 1;
	
	int total_count = 0;
	
	int dp[k];
	
	dp[0] = umap[temp[l]];
	for(int i=1;i<k;i++)
		dp[i] = 0;
	
	
	for(int j=l-1;j>=0;j--)
	{
		int cr = umap[temp[j]];
		for(int r=k-1;r>0;r--)
		{
			ll t1 = (dp[r] + ((ll)cr*dp[r-1])%mod)%mod;
			dp[r] = (int)t1;
		}
		ll t2 = ((ll)dp[0] + cr)%mod;
		dp[0] = (int) t2;
	}
	
	for(int tr=0;tr<k;tr++)
	{
		ll t3 = ((ll)total_count + dp[tr])%mod;
		total_count = t3;
	}
	
	total_count = total_count + 1;
	cout<<total_count<<endl;
	return 0;
}
