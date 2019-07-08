#include<bits/stdc++.h>
using namespace std;
#define size 1000001

// 1 asan 
// 0 boyan

int dp[2][size];

int findWinner(int n,int turn,int k,int l)
{
	int temp = turn%2;
	
	if(n == 1 || n == k || n == l){
		return temp;
	}
	
	
	if(dp[temp][n] != -1)
		return dp[temp][n];
		
	if(n <= 0)
		return -1;
		
	int a=-1,b=-1,c=-1;
	
		
	a = findWinner(n-1,turn+1,k,l);
	
	if(n>=k)
		b = findWinner(n-k,turn+1,k,l);
	
	if(n>=l)
		c = findWinner(n-l,turn+1,k,l);
	
	
	if(a == temp || b == temp || c == temp){
		dp[temp][n] = temp;
		return temp;
	}
	else{
		dp[temp][n] = (temp ^ 1);
		return (temp ^ 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int k,l,m;
	cin>>k>>l>>m;
	
		for(int i=0;i<=1;i++)
		{ 
			for(int j=0;j<size;j++)
				dp[i][j] = -1;
		}
	
	string result = "";
	while(m--)
	{
		int n;
		cin>>n;
		
		int res = findWinner(n,1,k,l);
		
		if(res == 1)
			result = result + "A";
		else
			result = result + "B";
	}
	cout<<result<<endl;
	return 0;
}
