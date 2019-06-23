#include<bits/stdc++.h>
using namespace std;

bool isValid(int r,int c,int i,int j)
{
	if(i<=r-1 && j<=c-1)
		return true;
	return false;
}

int numUniquePathWithoutDp(int r,int c,int i,int j)
{
	if(i==(r-1) && j==(c-1))
		return 1;
	
	bool rht = isValid(r,c,i,j+1);
	bool dwn = isValid(r,c,i+1,j);
	
	int right_count = 0,down_count = 0;
	
	if(rht)
		right_count = numUniquePathWithoutDp(r,c,i,j+1);
	
	if(dwn)
		down_count = numUniquePathWithoutDp(r,c,i+1,j);
		
	return (right_count + down_count);
}

int numUniquePathDp(int **dp, int r,int c,int i,int j)
{
	if(i==(r-1) && j==(c-1)){
		dp[i][j] = 1;
		return 1;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	bool rht = isValid(r,c,i,j+1);
	bool dwn = isValid(r,c,i+1,j);
	
	int right_count = 0,down_count = 0;
	
	if(rht)
		right_count = numUniquePathWithoutDp(r,c,i,j+1);
	
	if(dwn)
		down_count = numUniquePathWithoutDp(r,c,i+1,j);
		
	dp[i][j] = (right_count + down_count);
	return dp[i][j];
}

int numUniquePathFillDp(int m,int n)
{
	int **dp = new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i] = new int[n];
		for(int j=0;j<n;j++)
			dp[i][j] = 0;
	}
	
	// fill the last column 
	for(int i=0;i<m;i++)
		dp[i][n-1] = 1;
		
	// fill the last row
	for(int j=0;j<n;j++)
		dp[m-1][j] = 1;
		
		
	// fill the remaining dp matrix
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			dp[i][j] = dp[i][j+1] + dp[i+1][j];
		}
	}
	
	int result = dp[0][0];
	
	for(int i=0;i<m;i++)
		delete []dp[i];
		
	return result;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		
		int result = numUniquePathWithoutDp(m,n,0,0);
		cout<<result<<endl;
		
		int **dp = new int*[m];
		for(int i=0;i<m;i++)
		{
			dp[i] = new int[n];
			for(int j=0;j<n;j++)
				dp[i][j] = -1;
 		}
 		
 		int result2 = numUniquePathDp(dp,m,n,0,0);
 		cout<<result2<<endl;
		
		
		int result3 = numUniquePathFillDp(m,n);
		cout<<result3<<endl;
	}
}
