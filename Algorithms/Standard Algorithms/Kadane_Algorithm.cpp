#include<bits/stdc++.h>
using namespace std;


int LargestSubsetSum(int *arr,int n)
{
	int current_sum = 0;
	int best_sum = 0;
	
	for(int i=0;i<n;i++)
	{
		current_sum = current_sum+arr[i];
		
		if(current_sum > best_sum)
		{
			best_sum = current_sum;
		}
		
		if(current_sum < 0)
		{
			current_sum = 0;
		}
	}
	
	return best_sum;
}


int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	
	int *arr = new int[n];
	
	cout<<"Enter the array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int best_sum = LargestSubsetSum(arr,n);
	
	cout<<"Largest sum of contigous subarray : "<<best_sum<<endl;
	
	delete arr;
	
	return 0;
}
