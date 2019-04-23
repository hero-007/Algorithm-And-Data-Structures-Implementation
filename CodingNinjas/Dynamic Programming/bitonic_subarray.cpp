#include<bits/stdc++.h>
using namespace std;

int get_bitonic(int *arr,int n)
{
	int lis_left[n];
	int lis_right[n];
	
	for(int u=0;u<n;u++)
	{
		lis_left[u] = 1;
		lis_right[u] = 1;
	}
	
	//generate lis array from left
	for(int i=1;i<n;i++)
	{
		int k = arr[i];
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j] < k)
			{
				if((lis_left[j]+1) > lis_left[i])
					lis_left[i] = lis_left[j]+1;	
			}	
			if(arr[j] == k)
			{
				if((lis_left[j]) > lis_left[i])
					lis_left[i] = lis_left[j];
			}
		}	
	}
	
	//generate lis array from right 
	for(int j=n-2;j>=0;j--)
	{
		int k = arr[j];
		for(int i=j+1;i<n;i++)
		{
			if(arr[i] < k)
			{
				if((lis_right[i]+1) > lis_right[j])
					lis_right[j] = lis_right[i]+1;
			}
					
			if(arr[i] == k)
			{
				if((lis_right[i]) > lis_right[j])
					lis_right[j] = lis_right[i];
			}
		}
	}
	
	
	int maxk = INT_MIN;
	for(int k=0;k<n;k++)
	{
		lis_right[k] = lis_left[k]+lis_right[k]-1;
		if(lis_right[k] > maxk)
			maxk = lis_right[k];
	} 
	
	return maxk;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int result = get_bitonic(arr,n);
	cout<<result<<endl;
	return 0;
}
