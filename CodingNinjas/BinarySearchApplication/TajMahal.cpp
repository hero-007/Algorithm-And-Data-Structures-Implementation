#include<bits/stdc++.h>
using namespace std;

long long getValueOfT(int a,int i,int n)
{
	long long t = 0;
	long long st = 0;
	long long ed = INT_MAX;
	while(st <= ed)
	{
		long long mid = (st+ed)/2;
		
		long long temp = i+mid*n;
		if(temp >= a)
		{
			ed = mid-1;
			t = mid;
		}
		else
		{
			st = mid+1;
		}
	}
	
	return (i+n*t);
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	int pos, min = INT_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		long long temp = getValueOfT(arr[i],i,n);
		if(temp < min)
		{
			min = temp;
			pos = i+1;
		}
	}
	
	cout<<pos<<endl;
}
