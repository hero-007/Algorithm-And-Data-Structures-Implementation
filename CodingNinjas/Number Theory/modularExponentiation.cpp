#include<bits/stdc++.h>
using namespace std;

int modularExpo(int a,int b,int c)
{
	if(a == 0)
		return 0;
		
	if(b == 0)
		return 1;
		
	if(b%2 == 0)
	{
		// b is even 
		long smallAns = modularExpo(a,b/2,c);
		long ans = (smallAns * smallAns)%c;
		return int((ans+c)%c);	// doing this will also handle the negative value of ans
	}
	else
	{
		// b is odd
		int smallAns = modularExpo(a,b-1,c);
		long ans = a%c;
		ans = (ans * smallAns)%c;
		return int((ans+c)%c);
	}
}

int main()
{
	cout<<modularExpo(2,10,5)<<endl;
	return 0;
}
