#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		int t1 = (n*(n-1))/2;
		int t2 = t1+n;
		int t3 = n-1;
		
		int res = 0;
		
		if(m == t2){
			res = n;
		}
		else if(m >= t1 && m < t2){
			res = n-1;
		}
		else if(m == n){
			res = 2;
		}
		else if(m == t3){
			res = 1;
		}
		else if(m > n && m < t1)
		{
			// pass
			int ans = -1;
			
			for(int k=0;k<n;k++)
			{
				for(int x=3;x<=(n-1);x++)
				{
					int temp1 = 2*m;
					int temp2 = (n*x)-k;
					
					if(temp1 == temp2)
					{
						if(k == 0)
						{
							ans = x;
						}
						else
						{
							ans = x-1;
						}
						break;
					}
				}
				
				if(ans != -1)
					break;
			}
			
			res = ans;
		}
		else{
			res = -1;
		}
		
		cout<<res<<endl;
	}
}
