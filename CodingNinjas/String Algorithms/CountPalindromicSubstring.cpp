#include<bits/stdc++.h>
using namespace std;

int getLongestPalindromLength(string str)
{
	int count = 0;
	int n = str.length();
	
	for(int i=0;i<n;i++)
	{
		int ltr = i,rtr = i;
		
		// for odd length palindromic string
		while(str[ltr] == str[rtr] && ltr >= 0 && rtr < n)
		{
			count++;	
			ltr--;
			rtr++;
		}
		
		// for even length palindromic string
		if(i == n-1)
			break;
			
		ltr = i;
		rtr = i+1;
		while(str[ltr] == str[rtr] && ltr >= 0 && rtr < n)
		{
			count++;	
			ltr--;
			rtr++;
			
		}
	}
	
	return count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string stk;
		cin>>stk;
		int res = getLongestPalindromLength(stk);
		cout<<res<<endl;
	}
	
	return 0;
}
