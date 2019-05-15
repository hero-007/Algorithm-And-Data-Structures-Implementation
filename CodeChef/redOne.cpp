#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
	int t;
	cin>>t;
	
	int *arr = new int[1000000+1];
	int l = 1000000+1;
	
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 5;

	for(int i=3;i<l;i++)
	{
		int a = arr[i-1];
		int b = i;
		
		long temp1 = (long)a*b;
		long temp2 = (long)a+b;
		
		int temp3 = (int)(temp1%mod);
		int temp4 = (int)(temp2%mod);
		
		long temp5 = (long)temp3 + temp4;
		arr[i] = (int)(temp5%mod);
	}
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout<<arr[n]<<endl;
	}
	delete []arr;
	return 0;
}
