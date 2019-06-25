#include<bits/stdc++.h>
using namespace std;

int getIndex(string s)
{
	if(s == "RA")
		return 0;
	else if(s == "DES")
		return 1;
	else if(s == "CODE")
		return 2;
	else if(s == "TEST")
		return 3;
	else if(s == "DEP")
		return 4;
	else if(s == "M")
		return 5;
}

bool checkCount(int *arr)
{
	for(int i=0;i<6;i++)
	{
		if(arr[i] != 1)
			return false;
	}	
	return true;
}

void resetCount(int *arr)
{
	for(int i=0;i<6;i++)
		arr[i] = 0;	
}

int getResult(string s)
{
	int l = s.length();
	
	int ftr = 0,ltr = 0;
	int count[6] = {0};
	int projectCount = 0;
	
	while(ltr < l)
	{
		char ch = s[ltr];
		if(ch == ' ')
		{
			int k = ltr - ftr;
			string st = s.substr(ftr,k);
			int indx = getIndex(st);
			
			if(count[indx] == 1)
			{
				resetCount(count);
			}
			
			count[indx]++;
			
			bool allSet = checkCount(count);
			
			if(allSet)
			{
				projectCount++;
				resetCount(count);
			}
			
			ftr = ltr + 1;
			if(ftr == l)
				break;
		}
		
		ltr++;
	}
	
	return projectCount;
}

int main()
{
	string s;
	getline(cin,s);
	
	int result = getResult(s);
	cout<<result<<endl;
	
	return 0;
}
