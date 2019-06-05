#include<bits/stdc++.h>
using namespace std;

void buildZ(int *Z,string str)
{
	// This function will build Z array for str
	int l=0,r=0;
	int n = str.length();
	
	for(int i=1;i<n;i++)
	{
		if(i > r)
		{
			// i does not lie between l and r
			// Z for this does not exist
			l = i;
			r = i;
			while(r<n && str[r-l] == str[r])
			{
				r++;
			}
			Z[i] = r-l;
			r--;	
		}
		else
		{
			// i lies btw l and r
			int k = i-l;
			if(Z[k] <= r-i)
			{
				// Z for this value already exist
				Z[i] = Z[k];	
			}
			else
			{
				// Some part of Z is already included 
				// you have to start matching further
				l = i;
				while(r < n && str[r-l] == str[r]){
					r++;
				}
				Z[i] = r-l;
				r--;
			}
		}
	}
}

void searchString(string text,string pattern)
{
	string str = pattern+"$"+text;
	int n = str.length();
	int *Z = new int[n]();
	
	buildZ(Z,str);
	cout<<"indexes of matched pattern : ";
	for(int i=0;i<n;i++)
	{
		if(Z[i] == pattern.length())
		{
			cout<<i-pattern.length()-1<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	string text,pattern;
	cout<<"Enter the text : ";
	cin>>text;
	cout<<"Enter the pattern : ";
	cin>>pattern;
	
	searchString(text,pattern);
	
	return 0;
}
