#include<bits/stdc++.h>
using namespace std;

int cnv2int(string st)
{
	int l = st.length();
	int res = 0;
	for(int i=0;i<l;i++)
	{
		res = (res*10)+((int)st[i]-48);
	}
	return res;
}

int * numArr(string st,int n)
{
	int *arr = new int[n];
	st = st+',';
	int l = st.length();
	int ft  = 0,sk =0,ctr = 0;
	for(int i=0;i<l;i++)
	{
		char ch = st[i];
		if(ch == ',')
		{
			string s = st.substr(ft,sk);
			ft = i+1;
			sk = 0;
			int ak = cnv2int(s);
			arr[ctr] = ak;
			ctr++;
			continue;
		}
		sk++;
	}
	
	return arr;
}
int main()
{
	int n;
	cin>>n;
	string st;
	cin>>st;
	
	int *ar = numArr(st,n);
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += ar[i];
	cout<<sum<<endl;
	
}
