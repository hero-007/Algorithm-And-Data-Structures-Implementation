#include<bits/stdc++.h>
using namespace std;


int mini_time = INT_MAX;

void CombinationGenerator(int [],int [], int, int, int, int);
int calc_min_hour(int [],int);

void CombinationParent(int arr[],int n,int r)
{
	int data[r];
	sort(arr,arr+n,greater<int>());
	CombinationGenerator(arr,data,n,r,0,0);
}

// index -> data
// i -> arr
void CombinationGenerator(int arr[],int data[],int n,int r,int i,int index)
{
	if(index == r)
	{
		int temp = calc_min_hour(data,r);
		if(temp < mini_time)
			mini_time = temp;
	}
	
	if(i >= n)
		return;
		
	data[index] = arr[i];
	CombinationGenerator(arr,data,n,r,i+1,index+1);
	CombinationGenerator(arr,data,n,r,i+1,index);
}

int calc_min_hour(int data[],int r)
{
	int min_diff = 0;
	int max_val = data[0];
	for(int i=1;i<r;i++)
	{
		min_diff = min_diff + (max_val - data[i]);
	}
	
	return min_diff;
}

int main()
{
	int t,i=1;
	
	cin>>t;
	
	while(t-- != 0)
	{
		int n,p;
		cin>>n>>p;
		
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		CombinationParent(arr,n,p);
		cout<<"Case #"<<i<<": "<<mini_time<<endl;
		mini_time = INT_MAX;
		i++;
		
	}
	return 0;
}
