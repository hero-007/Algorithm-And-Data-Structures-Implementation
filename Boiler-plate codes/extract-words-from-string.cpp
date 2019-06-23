/** Extracting words from string **/

#include<bits/stdc++.h>
using namespace std;


void getWords(string st)
{
	stringstream ss(st);
	
	while(ss)
	{
		string words;
		ss>>words;
		cout<<words<<endl;
	}
}

int main()
{
	string s;
	getline(cin,s);
	
	getWords(s);
	
	return 0;
}
