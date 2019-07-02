#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		unordered_map<char,int> count;
		
		for(char ch:s)
		{
			count[ch]++;
		}
		
		int l = s.length();
		unordered_map<char,int>::iterator it = count.begin();
		
		int odd_count = 0,even_count = 0;
		
		while(it!=count.end())
		{
			int a = (*it)->second;
			if(a%2 == 0)
				even_count++;
			else
				odd_count++;
		}
		
		if(l%2 == 0)
		{
			if(odd_count == 0 || odd_count > 2)
			{
				cout<<"!DPS"<<endl;
			}
			else
			{
				cout<<"DPS"<<endl;
			}
		}
		else
		{
			if(odd_count == 1 || odd_count == 3)
			{
				cout<<"DPS"<<endl;
			}
			else
			{
				cout<<"!DPS"<<endl;
			}
		}
	}
	
	return 0;
}
