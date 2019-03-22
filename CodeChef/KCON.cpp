#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max_Subset_Sum(int *arr,int l)
{
	// KADANE'S ALGORITHM
	ll maxSubsetSum = 0;
	ll currentMax = 0;
	
	for(int i = 0;i<l;i++)
	{
		currentMax = currentMax + arr[i];
		
		if(currentMax > maxSubsetSum)
		{
			maxSubsetSum = currentMax;
		}
		
		if(currentMax < 0)
		{
			currentMax = 0;
		}
	}
	
	return maxSubsetSum;
}

ll max_Array_Sum(int *arr,int n,int k,ll sum)
{
	ll kd_sum = max_Subset_Sum(arr,n);
	
	ll current_suffix_sum = 0,current_prefix_sum = 0;
	ll max_suffix_sum = INT_MIN, max_prefix_sum = INT_MIN;
	// calculate the max suffix sum 
	for(int i=n-1;i>=0;i--)
	{
		current_suffix_sum += arr[i];
		max_suffix_sum = max(current_suffix_sum,max_suffix_sum);
	}
	
	for(int i=0;i<n;i++)
	{
		current_prefix_sum += arr[i];
		max_prefix_sum = max(current_prefix_sum,max_prefix_sum);
	}
	
	if(k==1)
		return kd_sum;
	
	if(sum<0)
	{
		ll finl_ans = max(kd_sum,(max_suffix_sum+max_prefix_sum));
		return finl_ans;
	}
	else
	{
		ll ks = max_suffix_sum + (sum * (k-2)) + max_prefix_sum;
		ll finl_ans = max(kd_sum,ks);
		return finl_ans;
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t-- != 0)
	{
		int n,k;
		ll final_ans;
		cin>>n>>k;
		
		int *arr = new int[n];
		ll sum = 0;
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
			sum += arr[j];
		}
		
		final_ans = max_Array_Sum(arr,n,k,sum);
		cout<<final_ans<<endl;
		delete arr;
	}
	
	return 0;
}
