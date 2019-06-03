#include<iostream>
#include<string>

using namespace std;

bool ifExist(string s,string p)
{
	int n = s.length();
	int m = p.length();
	
	for(int i=0;i<=(n-m);i++)
	{
		bool status = true;
		for(int j=0;j<m;j++)
		{
			if(s[i+j] != p[j])
			{
				status = false;
				break;
			}
		}
		
		if(status == true)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string s,p;
	cout<<"Enter the main string : ";
	cin>>s;
	cout<<"Enter the pattern to match : ";
	cin>>p;
	
	bool result = ifExist(s,p);
	if(result)
	{
		cout<<"Pattern Exist"<<endl;
	}
	else
	{
		cout<<"Pattern does not exist"<<endl;
	}
	return 0;
}
