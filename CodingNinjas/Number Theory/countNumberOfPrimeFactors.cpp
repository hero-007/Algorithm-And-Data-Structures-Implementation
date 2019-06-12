#include<bits/stdc++.h>
using namespace std;

#define max 1000001

vector<int> *primeFactor()
{
	vector<int> *primes = new vector<int>(max);
	for(int i=0;i<max;i++)
		primes->at(i) = 0;
		
	// for multiples of 2
	for(int j=2;j<max;j+=2)
	{
		primes->at(j) = primes->at(j)+1;
	}
	
	// for all odd numbers
	for(int k=3;k<max;k++)
	{
		if(primes->at(k) == 0)
		{
			for(int r=k;r<max;r+=k)
			{
				primes->at(r) = primes->at(r)+1;
			}
		}
	}
	
	return primes;
}

int main()
{
	vector<int> *primes = primeFactor();
	while(true)
	{
		int n;
		cin>>n;
		
		cout<<primes->at(n)<<endl;
	}
}
