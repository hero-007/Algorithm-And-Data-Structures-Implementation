#include<bits/stdc++.h>
using namespace std;


vector<int>* countFactors(int n)
{
	vector<int> *factors = new vector<int>;
	int count = 0;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			factors->push_back(i);
		}
	}
	
	factors->push_back(n);
	
	return factors;
}

int badPermute(vector<int>* factors,int pos)
{
	if(pos == factors.size())
		return 1;
	
	
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int>* factors = countFactors(n);
		int res = badPermute(factors,0);
		cout<<res<<endl;	
	}
}
