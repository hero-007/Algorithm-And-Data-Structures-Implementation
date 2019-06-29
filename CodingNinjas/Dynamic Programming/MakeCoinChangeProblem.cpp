#include<bits/stdc++.h>
using namespace std;

void findChange(int n,int *coins,int *lastCoin)
{
	if(lastCoin[n] == -1){
		cout<<"Not possible to make coin change in given currency"<<endl;
		return;
	}
	
	while(n != 0)
	{
		cout<<coins[lastCoin[n]]<<" ";
		n = n - coins[lastCoin[n]];
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	
	int coins[] =  {7,2,3,6};
	int numCoins = sizeof(coins)/sizeof(int);
	
	int count[n+1];
	int lastCoin[n+1];
	for(int i=0;i<=n;i++)
	{
		count[i] = INT_MAX-1;
		lastCoin[i] = -1;
	}
	count[0] = 0;
	
	for(int i=0;i<numCoins;i++)
	{
		int coinVal = coins[i];
		for(int j=1;j<=n;j++)
		{
			if(j < coinVal)
				continue;
			else
			{
				int newCount = 1 + count[j - coinVal];
				if(newCount < count[j]){
					count[j] = newCount;
					lastCoin[j] = i;
				}
			}
		}
	}
	
	
	findChange(n,coins,lastCoin);
	
	// Print Count and lastCoin
	cout<<"Count : ";
	for(int i=0;i<=n;i++)
		cout<<count[i]<<" ";
	cout<<endl;
	
	cout<<"Last Coin : ";
	for(int j=0;j<=n;j++)
		cout<<lastCoin[j]<<" ";
	cout<<endl;

return 0;
}
