// NOT WORKING
#include<bits/stdc++.h>
using namespace std;

int countMax(int n,int &buffer)
{
	if(n <= 0)
		return 0;
	
	if(n == 1)
		return 1;
		
	int a = countMax(n-1,buffer);
	int b = countMax(n-3,buffer);
	
	int t1=0,t2=0,t3=0;
	if(buffer!=0)
	{
		t1 = a+buffer;
	}
	
	t2 = a + 1;
	
	buffer = b;
	t3 = 2*buffer;
	
	int res = max(t1,max(t2,t3));
	return res;
}

int main()
{
	int t;
	cin>>t;
	int buffer = 0;
	cout<<countMax(t,buffer)<<endl;
	return 0;
}
