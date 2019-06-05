#include<iostream>
using namespace std;

void generateSieve(int n,bool *sieve)
{
    for(int i=2;i*i<=n;i++)
    {
            if(sieve[i] == true)
            {
                // mark all its multiple as non prime
                for(int j=i*i;j<=n;j+=i)
                {
                    sieve[j] = false;
                }
            }
    }
}

int getPrimeCount(int n,bool *sieve)
{
    int count = 0;
    
    generateSieve(n,sieve);
    
    for(int i=2;i<=n;i++)
    {
        if(sieve[i] == true)
            count++;
    }
    
    return count;
}

int main(){
	int n;
    cin>>n;
    bool *sieve = new bool[n+1];
    for(int i=0;i<=n;i++)
        sieve[i] = true;
    
    sieve[0] = false;
    sieve[1] = false;
    
    int result = getPrimeCount(n,sieve);
    cout<<result<<endl;
	return 0;
}
