#include<bits/stdc++.h>
using namespace std;


int getLargestMinimum(int *arr,int n,int c)
{
	sort(arr,arr+n);
	
	int d=0;
	int st = 0;
	int et = arr[n-1]-arr[0];
	
	while(st<=et)
	{
		int mid_d = (st+et)/2;
		
		bool isPossible = true;
		int temp_c = c-1;
		int temp = 0;
		
		for(int i=1;(i<n && temp_c>0);i++)
		{
			int k = arr[i] - arr[temp];
			
			if(k >= mid_d)
			{
				temp = i;
				temp_c--;
			}
		}
		
		if(temp_c != 0)
			isPossible = false;
		
		if(isPossible)
		{
			st = mid_d+1;
			d = mid_d;
		}
		else
		{
			et = mid_d-1;
		}
	}
	
	return d;
}


int main()
{
	int t;
	cin>>t;
	
	while(t--!=0)
	{
		int n,c;
		cin>>n>>c;
		int arr[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int largest_possible_dist = getLargestMinimum(arr,n,c);
		cout<<largest_possible_dist<<endl; 
	}
	
	return 0;
}
