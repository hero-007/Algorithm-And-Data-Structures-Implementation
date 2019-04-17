#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the value of n : ";
	cin>>n;
	
	int a = n & (n-1);
	
	if(a == 0)
		cout<<n<<" is a power of 2"<<endl;
	else
		cout<<n<<" not a power of 2"<<endl;
		
	return 0;
}
