#include<bits/stdc++.h>
using namespace std;

int arr[100];

void fillCoins()
{
	arr[0] = 1;
	for(int i=1;i<100;i++)
	{
		arr[i] = arr[i-1] + (i+1);
	}	
}

int main()
{
	int t;
	cin>>t;
	
	fillCoins();
	
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int k=0;k<99;k++)
		{
			if(n == arr[k])
			{
				cout<<k+1<<endl;
				break;
			}
			
			if(n > arr[k] && n <= arr[k+1])
			{
				cout<<k+2<<endl;
				break;
			}
		}
	}
	
	return 0;
}
