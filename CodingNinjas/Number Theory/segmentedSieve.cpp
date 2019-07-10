#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define max 100001

vector<int>* primesSeive()
{
    // generate all the prime factors less than max
    bool isPrime[max];
    for(int i=0;i<max;i++)
    	isPrime[i] = true;
    
        
    for(int i=2;i*i<max;i++)
    {
        if(isPrime[i] == true)
        {
            // set all multiples of i as false
            for(int j=i*i;j<max;j+=i)
                isPrime[j] = false;
        }
    }
    
    vector<int> *pr = new vector<int>();
    for(int j=2;j<max;j++)
    {
        if(isPrime[j])
            pr->push_back(j);
    }
    
    return pr;
}

void findPrime(vector<int>* &primes,ll l,ll r)
{
    bool isPrime[r-l+1];
    
    for(int i=0;i<=(r-l);i++)
        isPrime[i] = true;
        
    for(int i=0;primes->at(i)*(ll)primes->at(i) <=r; i++)
    {
        int curr_prime = primes->at(i);
        // find the multiple of curr_prime, which is just smaller or equal to l
		
		ll base = (l/curr_prime)*curr_prime;
		
		if(base < l)
			base += curr_prime;
			
		for(ll j=base;j<=r;j+=curr_prime)
		{
			isPrime[j-l] = false;
		}
		
		// if l/curr_prime = 0 then our curr_prime will also become false in the above process and we need to make it true
		// in this case base is also a prime number
		if(base == curr_prime)
			isPrime[base-l] = true;
    }
    
   	// now print the prime numbers from l to r
   	for(int i=0;i<=r-l;i++)
   	{
   		if(isPrime[i] == true)
		   	cout<<i+l<<endl;	
	}
	
}

int main() {
	vector<int> *primes = primesSeive();
	int t;
	cin>>t;
	
	while(t--)
	{
	    ll l,r;
	    cin>>l>>r;
	    
	    findPrime(primes,l,r);
	}
	
	return 0;
}
