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
		
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		
		int count = 0;
		
		for(int i=0;i<n;i++)
		{
			int current_price = arr[i];
			int j = i-1;
			int ct = 5;
			
			bool res = true;
			while(ct > 0 && j >= 0)
			{
				ct--;
				if(arr[j] <= current_price)
				{
					res = false;
					break;
				}
				j--;
			}
			
			if(res == true)
				count++;
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}
