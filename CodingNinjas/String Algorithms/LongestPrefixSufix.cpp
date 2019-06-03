#include<bits/stdc++.h>
using namespace std;

int* longestPrefixSufix(string pattern)
{
	int l = pattern.length();
	int *lps = new int[l];
	
	lps[0] = 0;
	int i,j;
	j = 0;
	i = 1;
	
	while(i<l)
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


int main()
{
	string a;
	cin>>a;
	
	int * lps = longestPrefixSufix(a);
	int n = a.length();
	
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	
	delete []lps;
}
