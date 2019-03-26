#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<long> multiset(n);
	for(int i=0;i<n;i++)
	{
		cin>>multiset[i];
	}
	
	set<long> queries;
	long max_iter = 0;
	for(int j=0;j<m;j++)
	{
		long temp;
		
		cin>>temp;
		queries.insert(temp);
		
		if(temp > max_iter)
		{
			max_iter = temp;
		}
	}

	
	int move_number = 1;
	while(max_iter-- != 0)
	{
		sort(multiset.begin(),multiset.end(),greater<int>());
		long a = multiset[0];
		
		if(queries.find(move_number) != queries.end())
		{
			cout<<a<<endl;
			
		}
		a = floor(a/2);
		multiset[0] = a;
		sort(multiset.begin(),multiset.end(),greater<long>());
			
		if(a == 0)
			multiset.pop_back();
		move_number++;
	}

	
	return 0;
}
