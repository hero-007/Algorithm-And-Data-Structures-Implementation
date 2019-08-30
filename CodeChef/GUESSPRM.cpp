#include<bits/stdc++.h>
using namespace std;

#define lim 100000
#define lim_square 10000000000
#define ll long long 
#define fl fflush(stdout)
vector<int> f;
int prime_list[] = {2,3,5,7,11,13,17,19,23,29};

void genPrime(ll n)
{
	// this function generates all the prime factors of n
	if(n%2==0)f.push_back(2);
	while (!(n&1)) { 
		n >>= 1;
	} 
	for (ll i = 3; i*i<=n; i += 2) { 
		if(n%i==0)f.push_back(i);
		while(n%i==0)n/=i;
	} 
    if (n > 2) f.push_back(n);
}

int findUnique()
{
	// this function will return an interger for which modulus of all candidate prime is unique
	for(int i=f.size();i<=31623;i++)
	{
		set<int> temp;
		ll rt = i*i;
		for(auto it:f)
		{
			temp.insert(rt%it);
		}
		
		if(temp.size() == f.size())
			return i;
	}
}

int gprime(ll r,int k)
{
	ll rt = k*k;
	for(auto it:f)
	{
		if(rt%it == r)
			return it;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string resp;
		ll r;
		cout<<"1 "<<lim<<"\n";fl;
		cin>>r;
		genPrime(lim_square - r);
		int k = findUnique();
		cout<<"1 "<<k<<"\n";fl;
		cin>>r;
		int pr = gprime(r,k);
		cout<<"2 "<<pr<<"\n";fl;
		cin>>resp;
		if(resp[0]!='Y')
			break;
		f.clear();
	}
	return 0;
}
