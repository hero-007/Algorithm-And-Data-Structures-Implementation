/**
Qusetion - Given to binary strings - 'a' and 'b' both of the same length. Make string 'a' equal to 'b', you can perform only two operations to make both the
strings equal -

1 - flip ---------- Cost = 1
2 - swap(i,j) ----- Cost = |i-j|

Objective is two make the two binary strings equal in minimum cost.

input - 1 <= n <= 10^6

output - Integer denoting the minimum cost possible

**/

#include<bits/stdc++.h>
using namespace std;

void invertBit(string &arr,int a)
{
	if(arr[a] == '1')
		arr[a] = '0';
	else
		arr[a] = '1';

	return;
}

int main()
{
	int n;
	string a,b;
	cin>>n;
	cin>>a>>b;
	int min_cost = 0;
	
	
	for(int i=0;i<n;i++)
	{
		if(a[i] == b[i])
			continue;
		else
		{
			if((i+1)<n && a[i+1]!=a[i] && a[i+1]!=b[i+1])
			{
				invertBit(a,i);
				invertBit(a,i+1);
				min_cost += 1;
			}
			else
			{
				invertBit(a,i);
				min_cost += 1;
			}
		}
	}
	
	cout<<min_cost<<endl;
	return 0;
}
