#include<bits/stdc++.h>
using namespace std;

int *longestPrefixSuffix(string pattern)
{
	int n = pattern.length();
	int *lps = new int[n];
	
	lps[0] = 0;
	int j = 0;
	int i = 1;
	
	while(i < n)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	
	return lps;
}


bool kmpPatternMatching(string text,string pattern)
{
	int text_len = text.length();
	int pattern_len = pattern.length();
	
	int *lps = longestPrefixSuffix(pattern);
	
	int i=0,j=0;
	while(i < text_len && j < pattern_len)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	
	delete []lps;
	
	if(j == pattern_len)
		return true;
	return false;
	
	
}

int main()
{
	int t;
	cout<<"Number of test cases : ";
	cin>>t;
	
	while(t--)
	{
		string s,p;
		cout<<"Enter the text : ";
		cin>>s;
		cout<<"Enter the pattern : ";
		cin>>p;
		
		bool result = kmpPatternMatching(s,p);
		
		if(result)
			cout<<"Pattern is matched"<<endl;
		else 
			cout<<"Pattern not matched"<<endl;
	}
	
	return 0;
}
