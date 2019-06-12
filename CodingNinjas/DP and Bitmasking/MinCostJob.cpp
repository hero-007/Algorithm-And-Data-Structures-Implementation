#include<bits/stdc++.h>
using namespace std;

int minCost(int cost[4][4],int n,int p,int mask)
{
	if(p == n)
		return 0;
		
	int minC = INT_MAX;
	for(int i=0;i<n;i++)
	{
		// check if ith bit of the mask is set or not 
		if(!(mask&(1<<i)))
		{
			int tempCost = minCost(cost,n,p+1,(mask|(1<<i))) + cost[p][i];
			if(tempCost < minC)
				minC = tempCost;
		}
	}
	
	return minC;
}

int main()
{
	int cost[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<minCost(cost,4,0,0)<<endl;
						
}
