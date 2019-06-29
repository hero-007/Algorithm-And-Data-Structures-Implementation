#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool checkAllAllocated(bool *bookStatus,int n)
{
	for(int i=0;i<n;i++)
	{
		if(!bookStatus[i])
			return false;
	}
	return true;
}

int maxChangesPossible(int n,int currBook,bool *bookStatus)
{
	if(currBook == n)
	{
		bool st = checkAllAllocated(bookStatus,n);
		if(st)
			return 1;
		else
			return 0;
	}
	
	int result = 0;
	
	for(int i=0;i<n;i++)
	{
		if(i == currBook || bookStatus[i] == true)
			continue;
		
		bookStatus[i] = true;
		int k = maxChangesPossible(n,currBook+1,bookStatus);
		bookStatus[i] = false;
		
		result = ((result%mod) + (k%mod))%mod;
	}
	
	return result;
}

int main()
{
	int n;
	cin>>n;
	
	bool bookStatus[n];
	for(int i=0;i<n;i++)
		bookStatus[i] = false;
		
	int res = maxChangesPossible(n,0,bookStatus);
	cout<<res<<endl;
	
	return 0;
}


