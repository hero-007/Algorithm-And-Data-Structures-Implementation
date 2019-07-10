#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--)
	{
		cpp_int n,k;
		cin>>n>>k;
		
		cpp_int a = k%n;	// number of person with 1 extra candy
		cpp_int b = n-a;
		cpp_int res;
		
		if(a > (n/2))
		{
			// start from 1
			res = b*2;
		}
		else if(a == (n/2))
		{
			// start from 2
			res = n-1;
		}
		else
		{
			// start from 2
			res = a*2;
		}
		
		cout<<res<<endl;
	}
}
