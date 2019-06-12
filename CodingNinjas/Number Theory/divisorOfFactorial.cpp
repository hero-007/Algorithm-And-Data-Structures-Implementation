#include<iostream>
#include<vector>
using namespace std;

#define max 500001
#define mod 1000000007

vector<int>* fillSieve()
{
	bool sieve[max];
    for(int i=0;i<max;i++)
        sieve[i] = true;
    sieve[1] = false;
    
    for(int i=2;i*i<=max;i++)
    {
        if(sieve[i] == true)
        {
            for(int j=i*i;j<=max;j+=i)
            {
                sieve[j] = false;
            }
        }
    }
    
    vector<int> *primes = new vector<int>();
    primes->push_back(2);
    for(int i=3;i<=max;i+=2)
    {
    	if(sieve[i])
    		primes->push_back(i);
	}
	
	return primes;
}

long long getFactor(int n,vector<int>* &primes)
{
	long long result = 1;
	for(int i=0;primes->at(i)<=n;i++){
		int k = primes->at(i);
		long long count = 0;
		while((n/k)!=0){
			count = (count + (n/k))%mod;
			k = k*primes->at(i);
		}
		result = (result * ((count+1)%mod))%mod;
	}
	return result;
}

int main(){
	int t;
    cin>>t;
	vector<int> *primes = fillSieve();
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<getFactor(n,primes)<<endl;
    }
    
	return 0;
}
