#include<string>
#include<iostream>
using namespace std;

//function to reverse a given string
void reverse_string(string str,int st,int ed)
{
	if(st == ed)
		return;
		
	char ch = str[st];
	str[st] = str[ed];
	str[ed] = ch;
	reverse_string(str,st+1,ed-1);
}

string getString(string str)
{
	string result = "";
	int l = str.length();
	int first = 0,last = 0;
	for(int i=0;i<l;i++)
	{
		if(str[i] == ' ')
		{
			int a = i - first;
			string stk = str.substr(first,a);
			reverse_string(stk,0,stk.length());
			result = result + stk + " ";
			first = i+1;
		}
		
	}
}

string rev(string str)
{
	string stm = "";
	for(int i=str.length()-1;i>=0;i--)
	{
		stm = stm+str[i];
	}
	
	stm = stm+" ";
	string output = getString(stm);
	return output;
}

int main()
{
	string ss;
	getline(cin,ss);
	
	// string result = rev(ss);
	string g = "hello";
	ss += g;
	cout<<ss<<endl;
	
	return 0;
}
