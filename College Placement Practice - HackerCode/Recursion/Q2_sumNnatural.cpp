#include<iostream>
using namespace std;

int first_N_natural(int n)
{
	if(n == 1)
		return 1;
	
	return (n + first_N_natural(n-1));
}

int main()
{
	int n;
	cin>>n;
	int result = first_N_natural(n);
	cout<<result<<endl;
}
