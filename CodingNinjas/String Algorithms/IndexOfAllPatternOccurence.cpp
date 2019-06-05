#include<bits/stdc++.h>
using namespace std;

int * longestPrefixSuffix(string pattern)
{
	int l = pattern.length();
	int *lps = new int[l];
	
	
	int i=1,j=0;
	lps[0] = 0;
	
	while(i < l)
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

vector<int>* getPatternOccurenceIndexes(string text,string pattern)
{
	int text_len = text.length();
	int pat_len = pattern.length();
	
	int i = 0,j = 0;
	int *lps = longestPrefixSuffix(pattern);
	
	vector<int> *result = new vector<int>();
	while(i < text_len)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
			
			if(j == pat_len)
			{
				result->push_back(i-j);
				j = 0;
			}
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
	return result;
}

int main()
{
	string text,pattern;
	cout<<"Enter the text : ";
	cin>>text;
	cout<<"Enter the pattern : ";
	cin>>pattern;
	
	vector<int> *result = getPatternOccurenceIndexes(text,pattern);
	int n = result->size();
	
	cout<<"Indexes of the pattern : ";
	
	if(n == 0)
	{
		// no matching pattern was found 
		cout<<-1;
	}
	vector<int>::iterator it = result->begin();
	
	while(it!=result->end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	
	return 0;
}
