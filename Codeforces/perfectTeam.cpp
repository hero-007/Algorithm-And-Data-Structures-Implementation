#include<bits/stdc++.h>
using namespace std;


int main()
{
	int q;
	cin>>q;
	
	
	while(q--)
	{
		int c,m,x;
		cin>>c>>m>>x;
		
		int a = min(c,min(m,x));
		int ans = -1;
		
		ans = a;
		c = c-a;
		m = m-a;
		x = x-a;
		
		if(x != 0)
		{
			ans = a;
		}
		else
		{
			// calculate the number of teams that can be formed using remaining c and m
			int f = min(c,m);
			
			int res = (c+m)/3;
			ans = ans + res;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
