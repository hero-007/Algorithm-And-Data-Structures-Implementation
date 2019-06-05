#include<bits/stdc++.h>
using namespace std;

int getHiCount(string str,int start,int l)
{
	if(start+1 == l)
		return 0;
	else
	{
		int beforeCount = getHiCount(str,start+1,l);
		
		if(str[start] == 'H' && str[start+1] == 'i')
			return beforeCount+1;
		return beforeCount;
	}
}

int main()
{
	string str;
	cin>>str;
	
	int result = getHiCount(str,0,str.length());
	cout<<result<<endl;
	
	return 0;
}
