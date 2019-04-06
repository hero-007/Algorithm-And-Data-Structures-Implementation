#include<bits/stdc++.h>
using namespace std;

bool checkIfPossible(int arr[],int n,int k,int first_max)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]%first_max == k)
			return true;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	int first_max = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
		if(arr[i] > first_max)
			first_max = arr[i];
	}
	
	int st = 0;
	int ed = first_max-1;
	int temp = 0;
	
	while(st <= ed)
	{
		int mid = (st+ed)/2;
		
		if(checkIfPossible(arr,n,mid,first_max))
		{
			st = mid+1;
			temp = mid;
		}
		else
		{
			ed = mid-1;
		}
	}
	
	cout<<temp<<endl;
	
}
