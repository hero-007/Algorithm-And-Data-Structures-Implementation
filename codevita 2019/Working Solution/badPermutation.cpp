#include<bits/stdc++.h>
using namespace std;

int badPermute(int n)
{
	if(n == 0 || n == 1)
		return n;
		
	int res = (n-1) * badPermute(n-1) + (n-2) * badPermute(n-2);
	return res;
}

int countFactors(int n)
{
	int count = 0;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i == 0)
			count++;
	}
	
	return count+1;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int factors = countFactors(n);
		int res = badPermute(factors);
		cout<<res<<endl;	
	}
}
