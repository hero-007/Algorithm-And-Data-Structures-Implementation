#include<iostream>
#include<stack>

using namespace std;


string isBalanced(string s)
{
	stack<char> stk;
	int l = s.length();
	
	for(int i=0;i<l;i++)
	{
		char c = s[i];
		
		if(c=='{' || c=='[' || c=='(' )
			stk.push(c);
		else
		{
			char r;
			if(c=='}')
				r='{';
			else if(c==')')
				r='(';
			else
				r='[';
			
			if(!stk.empty())
			{
				char m = stk.top();
				if(r == m)
					stk.pop();
				else
					break;
			}
			else{
				return "NO";
			}
		}
	}
	
	if(stk.empty())
		return "YES";
	else
		return "NO";
}

int main()
{
	int t;
	printf("Enter the number of string : ");
	scanf("%d",&t);
	
	while(t-- != 0)
	{
		string k;
		printf("\nEnter the bracket sequence : ");
		cin>>k;
		
		string result = isBalanced(k);
		cout<<"Is string balanced : "<<result<<endl;
	}
	
	return 0;
}
