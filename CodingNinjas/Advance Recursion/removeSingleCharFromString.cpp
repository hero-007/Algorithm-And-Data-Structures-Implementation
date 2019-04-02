#include<bits/stdc++.h>
using namespace std;

void removeAllOccurence(char st[],char ch)
{
	if(st[0] == '\0')
		return;
	
	if(st[0] != ch)
		removeAllOccurence(st+1,ch);
	else
	{
		int i=0;
		for(i=0;st[i]!='\0';i++)
			st[i] = st[i+1];
		st[i-1] = '\0';
		
		removeAllOccurence(st,ch);
	}
	return;
}
int main()
{
	char s[100];
	cout<<"Enter a string : ";
	cin>>s;
	
	char ch;
	cout<<"Enter the character to remove : ";
	cin>>ch;
	
	removeAllOccurence(s,ch);
	cout<<"New String : "<<s<<endl;
}
