#include<bits/stdc++.h>
using namespace std;

int findLongestSubsequence(int *arr,int n)
{
	if(n == 1)
		return 1;
		
	int max_count = 1;
	
	int *lis = new int[n];
	for(int i=0;i<n;i++)
		lis[i] = 1;
		
	for(int i=1;i<n;i++)
	{
		int val = arr[i];
		for(int j=i-1;j>=0;j--)
		{
		    int temp = arr[j]-val;
			if(abs(temp) == 1 && lis[j]+1 > lis[i])
				lis[i] = lis[j] + 1;
		}
		
		if(lis[i] > max_count)
			max_count = lis[i];
	}
	
	return max_count;
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
			cin>>arr[i];
		
		int result = findLongestSubsequence(arr,n);
		cout<<result<<endl;
		
		delete []arr;
	}
	
	return 0;
}
