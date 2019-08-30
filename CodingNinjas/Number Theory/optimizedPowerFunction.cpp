#include<bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
	if(x == 0)
		return 0;
		
	if(n == 0)
		return 1;
		
	if(n%2 == 0)
	{
		// n is even 
		int k = power(x,n/2);
		return k*k;
	}
	else
	{
		// n is odd
		int k = power(x,n-1);
		return x*k;
	}
}

int main()
{
	cout<<power(2,5)<<endl;
	cout<<power(2,6)<<endl;
	cout<<power(2,8)<<endl;
	cout<<power(4,3)<<endl;
	cout<<power(5,5)<<endl;
	
	return 0;
}
