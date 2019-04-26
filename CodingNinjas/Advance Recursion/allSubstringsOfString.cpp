#include<iostream>
using namespace std;

void printSubstring(string str,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int count = j-i+1;
			string stk = str.substr(i,count);
			cout<<stk<<endl;
		}
	}
	
}

int main()
{
	string str;
	cin>>str;
	int n = str.length();
	printSubstring(str,n);
	return 0;
}
