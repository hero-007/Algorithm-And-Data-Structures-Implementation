#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define max 10000001

int arr[60];
void fill_arr()
{
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2;i<60;i++)
	{
		arr[i] = (arr[i-1] + arr[i-2])%10;
	}
}

int find_log(ll n)
{
	int ctr = 0;
	while(n != 1)
	{
		ctr++;
		n = n/2;
	}
	
	return ctr;
}

ll power(int x,int n)
{
	if(x == 0)
		return 0;
		
	if(n == 0)
		return 1;
		
	if(n%2 == 0)
	{
		// n is even 
		ll k = power(x,n/2);
		return k*k;
	}
	else
	{
		// n is odd
		ll k = power(x,n-1);
		return x*k;
	}
}


int main()
{
	int t;
	cin>>t;
	fill_arr();
	while(t--)
	{
		ll n;
		cin>>n;
		
		int k = find_log(n);
		ll n_fib = power(2,k);
		
		int ktr = (n_fib-2)%60;
		cout<<arr[ktr]<<endl;
	}
}
