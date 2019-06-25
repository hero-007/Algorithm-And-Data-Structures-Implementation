#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	if(n <= 3)
	{
		for(int i=1;i<=n;i++)
			cout<<"5";
		cout<<endl;
	}
	else
	{
		int k = n/3;
		int a = 0,b = 0;
		int status = -1;
		for(int i=k;i>=1;i--)
		{
			a = 3*i;
			b = n - a;
			
			if(b%5 == 0)
			{
				status = 1;
				break;
			}
		}
		
		if(status == 1)
		{
			for(int i=1;i<=a;i++)
				cout<<"5";
			
			for(int j=1;j<=b;j++)
				cout<<"3";
			cout<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
				cout<<"5";
			cout<<endl;
		}
	}
	
	return 0;
}
