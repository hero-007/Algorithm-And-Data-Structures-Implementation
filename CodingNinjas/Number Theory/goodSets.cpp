#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;
#define max 1000001

ll getFact(int st[],int n)
{
    vector<ll> sieve(max);
    for(int i=0;i<max;i++)
    {
        sieve[i]  = 0;
    }
    for(int i=0;i<n;i++)
    {
        int a = st[i];
        sieve[a] = 1;
    }
    
    for(int j=0;j<n;j++)
    {
        int k = st[j];
        for(int c=2*k;c<max;c+=k)
        {
            if(sieve[c]!=0)
            {
                sieve[c] = ((sieve[c]%mod) + (sieve[k]%mod))%mod;
            }
        }
    }
    
    ll count = 0;
    for(int p=0;p<n;p++)
    {
        count = ((count%mod) + (sieve[st[p]]%mod))%mod;
    }
    return count%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int st[n];
        for(int i=0;i<n;i++)
            cin>>st[i];
        sort(st,st+n);
        ll result = getFact(st,n);
        cout<<result<<endl;
    }
	return 0;
}
