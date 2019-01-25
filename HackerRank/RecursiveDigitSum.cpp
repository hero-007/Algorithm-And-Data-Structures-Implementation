#include <iostream>
#include<string>
#include <sstream>

using namespace std;

int convertChar2Int(char ch)
{
    int a = ch - 48;
    return a;
}

int superDigit(string a,int n)
{
	if (n > 1)
	{
		for(int i=1;i<n;i++)
			a = a+a;
	}
	int sum = 0;
	for(int i=0;i<a.length();i++)
	{
		char c = a[i];
		int a = convertChar2Int(c);
		sum += a;
	}
	
	if (sum/10 == 0)
		return sum;
	else
	{
		ostringstream stk;
		stk << sum;
		string new_a = stk.str();
		superDigit(new_a,1);
	}
}

int main()
{
	int k = superDigit("123",3);
	cout<<k<<endl;
	
	return 0;
}
