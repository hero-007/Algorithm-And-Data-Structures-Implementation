#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int alphaCode(int *arr,int size)
{
    if(size == 0 || size == 1)
		return 1;
	
	long long *output = new long long[size+1];
	output[0] = 1;
	output[1] = 1;
	
	for(int i=1;i<size;i++)
	{
        output[i+1]=0;
		int k = arr[i-1]*10 + arr[i];
        if(arr[i]!=0)
        {
            output[i+1] += output[i];
        }
        if(arr[i]==0 && k>=10 && k<=26)
        {
            if(i>1)
            {
                output[i+1] =((output[i+1]%mod)+(output[i-1]%mod))%mod;
            }
            else
            {
                output[i+1]++;
            }
        }
        if(arr[i]!=0 && k>=10 && k<=26)
        {
            output[i+1]=((output[i+1]%mod)+(output[i-1]%mod))%mod;
        }
	}
	
	long long temp = output[size]%mod;
	delete []output;
	return temp;
}

int main()
{
    while(true)
    {
        string st;
        cin>>st;
        int size = st.length();
        
        if(st[0] == '0')
            break;
        
        int *arr = new int[size];
        for(int i=0;i<size;i++)
        {
            char ch = st[i];
            int a = (int)ch - 48;
            arr[i] = a;
        }
        
        long long result = alphaCode(arr,size);
        cout<<result<<endl;
        delete []arr;
    }
    
    return 0;
}
