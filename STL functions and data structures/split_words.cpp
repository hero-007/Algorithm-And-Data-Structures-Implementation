#include<bits/stdc++.h>
using namespace std;

void splitWords(string s)
{
	stringstream ss(s);
	
	while(ss){
		string word;
		ss>>word;
		
		cout<<word<<endl;
	}
}



int main()
{
	string s = "Hello Guys my name is Akhil";
	splitWords(s);
	return 0;
}
