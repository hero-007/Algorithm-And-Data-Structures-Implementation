#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll maxBitonicSubarraySum(int *arr,int n)
{
	ll *lis_left = new ll[n];
	ll *lis_right = new ll[n];
	for(int k=0;k<n;k++)
	{
		lis_left[k] = 0;
		lis_right[k] = 0;
	}
	
	ll max = INT_MIN;
	
	// fill lis_left array 
	lis_left[0] = (ll)arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i] > arr[i-1])
		{
			lis_left[i] = (ll)arr[i] + lis_left[i-1];
		}
		else
		{
			lis_left[i] = (ll)arr[i];
		}
	}
	
	// fill lis_right array
	lis_right[n-1] = (ll)arr[n-1];
	for(int j=n-2;j>=0;j--)
	{
		if(arr[j] > arr[j+1])
		{
			lis_right[j] = (ll)arr[j] + lis_right[j+1];
		}
		else
		{
			lis_right[j] = (ll)arr[j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		ll res = lis_left[i] + lis_right[i] - (ll)arr[i];
		
		if(res > max)
			max = res;
	}
	
	delete []lis_left;
	delete []lis_right;
	
	return max;
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int *arr = new int[n];
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>arr[i];
		}
		
		ll result = maxBitonicSubarraySum(arr,n);
		
		cout<<result<<endl;
		
		delete []arr;
	}
	
	return 0;
}
