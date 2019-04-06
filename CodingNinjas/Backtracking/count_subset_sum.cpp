#include<bits/stdc++.h>
using namespace std;


int ct = 0;

void countSubsetWithSum(int arr[],int cl,int sum,int n)
{
	if(sum == 0)
	{
		ct++;
		return;
	}
	
	int current = arr[cl];
	if(sum < current)
		countSubsetWithSum(arr,cl+1,sum,n);
	else
	{
		for(int i=cl+1;i<n;i++)
		{
			countSubsetWithSum(arr,i,sum-current,n);
		}
	}
	return;
}

int main()
{
	int n,sum;
	cout<<"Size of the array : ";
	cin>>n;
	
	int arr[n];
	cout<<"Enter the array elements : ";
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<"Enter the sum : ";
	cin>>sum;
	
	countSubsetWithSum(arr,0,sum,n);
	
	cout<<"Total subset possible = "<<ct<<endl;
	return 0;
}
