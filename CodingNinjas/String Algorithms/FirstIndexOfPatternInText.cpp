/**
String Search

Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.

Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3

Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1

**/

#include<bits/stdc++.h>
using namespace std;

int *longestPrefixSuffix(char pattern[])
{
	int n = strlen(pattern);
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


int findString(char text[], char pattern[]) {
	
	int *lps = longestPrefixSuffix(pattern);
	
    int text_len = strlen(text);
    int pat_len = strlen(pattern);
    
	int i=0,j=0;
    int first = -1;
	while(j < pat_len && i < text_len)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
            first = i-j;
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
	
	if(j == pat_len)
		return first;
	return -1;
}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

