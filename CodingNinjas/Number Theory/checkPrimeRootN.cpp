#include<iostream>
using namespace std;

bool checkPrime(int n)
{
    int ct = 0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                ct++;
            else
                ct+=2;
        }
    }
    
    if(ct == 2)
        return true;
    return false;
}

int getPrimeCount(int n)
{
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        bool status = checkPrime(i);
        if(status)
            count++;
    }
    
    return count;
}

int main(){
	int n;
    cin>>n;
    int result = getPrimeCount(n);
    cout<<result<<endl;
	return 0;
}
