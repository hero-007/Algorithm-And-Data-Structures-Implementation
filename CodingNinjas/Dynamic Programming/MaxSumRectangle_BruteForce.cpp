#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int st_i = i;
			int st_j = j;
			int sum = 0;
			for(int x = st_i;x<n;x++)
			{
				for(int y = st_j;y<m;y++)
				{
					sum += arr[x][y];
				}
			}
			arr[st_i][st_j] = sum;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int st_i = i;
			int 
		}
	}
}
