#include<bits/stdc++.h>
using namespace std;

void getTimeForBatch(vector< pair<int,int> > interval,int *arr,int n,int m)
{
	sort(interval.begin(),interval.end()); // sort the given vector in O(nlogn)
	
	for(int i=0;i<m;i++)
	{
		int p = arr[i];
		vector< pair<int,int> > :: iterator it = lower_bound(interval.begin(),interval.end(),make_pair(p,0));
		
		if(it->first == p)
			cout<<0<<endl;
		else if(it == interval.begin())
		{
			cout<<(it->first)-p<<endl;
		}
		else
		{
			if(it == interval.end())
			{
				it = it-1;
				if(it->second > p)
					cout<<0<<endl;
				else
					cout<<-1<<endl;
			}
			else
			{
				int temp = it->first;
				it = it-1;
				if(it->second > p)
					cout<<0<<endl;
				else
					cout<<temp-p<<endl;
			}
		}
		
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector< pair<int,int> > Interval;
		int arr[m];
		
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			pair<int,int> c(a,b);
			Interval.push_back(c);
		}
		
		for(int j=0;j<m;j++)
			cin>>arr[j];
			
		getTimeForBatch(Interval,arr,n,m); 
	}
	
	return 0;
}
