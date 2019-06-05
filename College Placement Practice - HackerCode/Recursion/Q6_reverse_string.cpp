#include<string>
#include<iostream>
using namespace std;

void reverse(string &str,int st,int ed)
{
	if(st == ed)
		return;
	
	char ch = str[st];
	str[st] = str[ed];
	str[ed] = ch;
	
	reverse(str,st+1,ed-1);
}

int main()
{
	string a;
	cin>>a;
	reverse(a,0,a.length()-1);
	cout<<a;
	
	return 0;
}
