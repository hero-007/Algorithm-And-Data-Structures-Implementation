#include<bits/stdc++.h>
using namespace std;

#define max 100001
#define ll long long 

map<int,ll> umap;

ll fillDP(int n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	
	if(umap.find(n) != umap.end())
		return umap[n];
		
	ll sum = fillDP(n/2) + fillDP(n/3) + fillDP(n/4);
	umap[n] = (sum > n)?sum:n;
	return umap[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while(cin>>n)
	{
		cout<<fillDP(n)<<endl;
	}	
	return 0;
}
