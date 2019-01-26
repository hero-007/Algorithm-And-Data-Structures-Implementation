#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t-- != 0)
	{
		int n;
		scanf("%d",&n);
		
		string str;
		cin>>str;
		
		int l = str.length();
		int current_pos = 0;
		int max = 0;
		
		while(current_pos < l)
		{
			// case 1 - if it is the first index 
			if (current_pos == 0)
			{
				if(str[current_pos]=='0' && str[current_pos + 1]!='1')
				{
					max++;
					current_pos +=2;
				}
				else
					current_pos +=1;
			}
			else if (current_pos == l-1) // case 2 - if current pos is the last index
			{
				if(str[current_pos]=='0' && str[current_pos - 1]=='0')
				{
					max++;
					current_pos +=1;
				}
				else
					current_pos +=1;
			}
			else // all the other cases are handled by this else block
			{
				if (str[current_pos]=='0' && str[current_pos+1]=='0' && str[current_pos-1]=='0')
				{
					max++;
					current_pos +=2;	
				}
				else
					current_pos+=1;	
			}
		}
		
		cout<<max<<endl;
	}
	
}
