#include<bits/stdc++.h>
using namespace std;

string getStringCombination(int t)
{
	if(t == 2)
		return "abc";
	else if(t==3)
		return "def";
	else if(t==4)
		return "ghi";
	else if(t==5)
		return "jkl";
	else if(t==6)
		return "mno";
	else if(t==7)
		return "pqrs";
	else if(t==8)
		return "tuv";
	else if(t==9)
		return "wxyz";
	else
		return "";
}

int genAllCombination(int n,string output[])
{
	if(n == 0)
	{
		output[0] = "";
		return 1;
	}
	
	int d = n%10;
	int new_n = n/10;
	string s = getStringCombination(d);
	int small_size = genAllCombination(new_n,output);
	int current_size = s.length();

	int sr = small_size*current_size;
	int k=0;
	for(int i=0;i<sr;i++)
	{
		output[i] = output[k];
		k++;
		
		if(k > small_size-1)
			k = 0;
	}
	
	int kh=0;
	for(int j=0;j<current_size;j++)
	{
		char ch = s[j];
		int st = small_size*kh;
		for(int h=st;h<(st+small_size);h++)
			output[h] = output[h]+ch;
		kh++;
	}
	
	return small_size*s.length();
}

int main()
{
	cout<<"Enter a number : ";
	int n;
	cin>>n;
	
	string output[100];
	int m = genAllCombination(n,output);
	
	for(int i=0;i<m;i++)
		cout<<output[i]<<endl;
	cout<<endl;
	
	return 0;
}
