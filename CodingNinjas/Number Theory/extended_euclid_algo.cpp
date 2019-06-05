/**
This algorithm is used to find the solution of linear diophantine equation, given (ax+by) = gcd(a,b);
solution of the above eqn is the integral value of x and y
**/

#include<iostream>
using namespace std;

class Triplet{
	public:
		int x;
		int y;
		int gcd;
};

Triplet extended_Euclid(int a,int b)
{
	// base case
	if(b == 0)
	{
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	
	Triplet smallAns = extended_Euclid(b,a%b);
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	
	Triplet soln = (a > b)?extended_Euclid(a,b):extended_Euclid(b,a);
	cout<<"GCD : "<<soln.gcd<<endl;
	cout<<"x : "<<soln.x<<endl;
	cout<<"y : "<<soln.y<<endl;
	
	return 0;
}
