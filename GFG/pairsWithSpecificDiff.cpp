#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int *arr = new int[n];
		bool *status = new bool[n];
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			arr[i] = a;
			status[i] = false;
		}
		
		int k;
		cin>>k;
		
		sort(arr,arr+n,greater<int>());
		
		int sum = 0;
		for(int i=0;i<n-1;i++)
		{
			if(status[i])
				continue;
				
			int val = arr[i];
			for(int j=i+1;j<n;j++)
			{
				int temp = (val > arr[j])?(val - arr[j]):(arr[j] - val);
					
				if(temp < k && !status[j] && !status[i])
				{
					sum = sum + val + arr[j];
					status[i] = true;
					status[j] = true;
					break;
				}
			}
		}
		
		cout<<sum<<endl;
		delete []arr;
	}
}
