#include<bits/stdc++.h>
using namespace std;



int main()
{
	string num;
	cin>>num;
	
	int l = num.length();
	
	int result = 0;
	int count = 0;
	
	while(count < l)
	{
		int ch = (int)num[count] - 48;
		result = ((result*10)%40 + (ch%40))%40;
		count++;
	}
	
	cout<<result<<endl;
	
}
