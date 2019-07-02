#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char *st,char ch,int n)
{
	if(st[0] == '\0')
		return;
		
	removeDuplicates(st+1,ch,n-1);
	
	if(st[0] == ch)
	{
		for(int j=1;j<=n;j++)
		{
			st[j-1] = st[j]; 
		}
		return;
	}
}

int main()
{
	char st[100];
	cin>>st;
	char ch;
	cin>>ch;
	
	removeDuplicates(st,ch,strlen(st));
	cout<<st<<endl;
}
