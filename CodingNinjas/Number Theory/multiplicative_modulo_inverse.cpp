#include<iostream>
using namespace std;

class Triplet{
public:
	int x;
	int y;
	int gcd;
};

Triplet findModuloInverse(int a,int b)
{
	if(b == 0)
	{
		Triplet ans;
		ans.x = 1;
		ans.y = 0;
		ans.gcd = a;
		return ans;
	}
	
	Triplet smallAns = findModuloInverse(b,a%b);
	Triplet ans;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	ans.gcd = smallAns.gcd;
	
	return ans;
}

int getMultiplicativeModuloInverse(int a,int m)
{
	Triplet result = findModuloInverse(a,m);
	return result.x;
}

int main()
{
	int a = 5,m = 17;
	// a and b should be co-prime inorder to give integral value of b i.e, multiplicative modulo inverse
	int result = getMultiplicativeModuloInverse(a,m);
	cout<<result<<endl;
	
	return 0;
}
