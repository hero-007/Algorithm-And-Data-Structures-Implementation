#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(a == 0)
		return b;
	return gcd(a%b,a);
}

int main()
{
	int a,b;
	cin>>a>>b;
	
	int result = (a > b)?gcd(a,b):gcd(b,a);
	cout<<result<<endl;
	
	int result_direct = __gcd(a,b);
	cout<<"Direct result using stl : "<<result_direct<<endl;
	return 0;
}
