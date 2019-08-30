#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1000001];

int cnv2num (string s)
{
	int num = 0;
	int i = 0;
	while(i < s.length())
	{
		int a = s[i] - '0';
		num = num*10 + a;
		i++;
	}
	return num;
}

int findDecoding(string st,int n)
{
	if(n == 0 || n == 1)
		return 1;
	
	if(dp[n]!=-1)
		return dp[n];
		
	string op1 = st.substr(0,1);
	string op2 = st.substr(0,2);
	
	// convert op1 and op2 to number 
	int a = cnv2num(op1);
	int b = cnv2num(op2);
	
	int t1 = 0,t2 = 0;
	if(a <= 25 && a >= 0)
		t1 = findDecoding(st.substr(1),n-1);
	if(b <= 25 && b >=0 && op2[0]!='0')
		t2 = findDecoding(st.substr(2),n-2);
		
	dp[n] = ((long)t1+t2)%mod;
	return dp[n];
}

int main()
{
	while(true)
	{
		string st;
		cin>>st;
		
		if(st == "0")
			break;
		
		memset(dp,-1,sizeof(dp));
		
		int result = findDecoding(st,st.length());
		cout<<result<<endl;
	}
	
	return 0;
}
