#include<bits/stdc++.h>
using namespace std;

int global_best = 0;

int LSS(int *arr,int l)
{
	int best_so_far = 0;
	int current_max = 0;
	
	if(l == 1)
	{
		if(arr[l-1] > 0)
			return arr[l-1];
		return 0;
	}
	
	best_so_far = LSS(arr,l-1);
	current_max = best_so_far+arr[l-1];
	
	if(current_max >= best_so_far)
	{
		best_so_far = current_max;
		if(best_so_far > global_best)
		{
			global_best = best_so_far;
		}
		return best_so_far;
	}
	return 0;
}

int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	
	int *arr = new int[n];
	
	cout<<"Enter the array elements : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int a = LSS(arr,n);
	cout<<"\nMax Subarray sum = "<<global_best<<endl;
	
	delete arr;
	return 0;
}
