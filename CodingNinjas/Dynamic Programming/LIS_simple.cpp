#include<bits/stdc++.h>
using namespace std;

void fill_lis(int *arr,int *lis_size,int n)
{
	// This function will create the LIS array 
	lis_size[0] = 1;
	for(int i=1;i<n;i++)
	{
		int k = arr[i];
		for(int j=i-1;j>=0;j--)
		{
			if(k >= arr[j])
			{
				if((lis_size[j]+1) > lis_size[i])
					lis_size[i] = lis_size[j]+1;
			}
		}
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	
	int arr[n];
	int lis_size[n] = {1}; // because at each index minimum possible length of the increasing subsequence is 1
	
	cout<<"Enter the elements of the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	fill_lis(arr,lis_size,n);
	
	// Search for the maxx element inside the LIS array 
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(lis_size[i] > max)
			max = lis_size[i];
	}
	
	cout<<"Longest Increasing Subsequence : "<<max<<endl;
	return 0;
}
