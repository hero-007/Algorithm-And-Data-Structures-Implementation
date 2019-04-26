#include<bits/stdc++.h>
using namespace std;

int getMinimumCost(int **input,int n,int m)
{
	int **dp = new int*[n];
	for(int i=0;i<n;i++)
		dp[i] = new int[m];
		
	dp[n-1][m-1] = input[n-1][m-1];
	
	// fill the last column
	for(int j=n-2;j>=0;j--)
		dp[j][m-1] = input[j][m-1] + dp[j+1][m-1];
		
	// fill the last row
	for(int k=m-2;k>=0;k--)
		dp[m-1][k] = input[m-1][k] + dp[m-1][k+1];
		
	// fill the remaining matrix
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			int c1 = dp[i][j+1];
			int c2 = dp[i+1][j+1];
			int c3 = dp[i+1][j];
			
			int res = min(c1,min(c2,c3));
			dp[i][j] = input[i][j] + res;
		}
	}
	
	int temp_res = dp[0][0];
	for(int i=0;i<n;i++)
		delete []dp[i];
	return temp_res;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int **input = new int*[n];
	for(int i=0;i<n;i++)
		input[i] = new int[m];
		
		
	// filling the input matrix 
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>input[i][j];
			}
		}
		
	cout<<getMinimumCost(input,n,m)<<endl;
	return 0;
}
