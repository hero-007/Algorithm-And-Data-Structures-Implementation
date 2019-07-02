#include<bits/stdc++.h>
using namespace std;

void eulPhi(int n)
{
	int eul[n+1];
	for(int i=1;i<=n;i++)
	{
		eul[i] = i;
	}
	
	for(int i=2;i<=n;i++)
	{
		if(eul[i] == i)
		{
			// i is a prime number 
			eul[i] = i-1;
			
			for(int j=2*i;j<=n;j+=i)
			{
				eul[j] = (eul[j] * (i-1))/i;
			}
		}
	}
	
	cout<<"Euler totient of "<<n<<" is : "<<eul[n]<<endl;
}

int main()
{
	int n;
	cin>>n;
	
	eulPhi(n);
}
