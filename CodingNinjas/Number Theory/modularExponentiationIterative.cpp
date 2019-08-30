#include<bits/stdc++.h>
using namespace std;

int modExpo(int a,int b,int c)
{
	if(a == 0)
		return 0;
		
	int ans = 1;
	
	while(b > 0)
	{
		if(b&1 != 0)
		{
			ans = (int)(((ans%c) * (long)(a%c))%c);
		}
		
		a = (int)(((a%c)*(long)(a%c))%c);
		b = b>>1;
	}
	
	return ans;
}

int main()
{
	cout<<modExpo(2,1024,5)<<endl;
	return 0;
}
