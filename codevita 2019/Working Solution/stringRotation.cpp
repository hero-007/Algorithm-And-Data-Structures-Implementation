#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(string st1,string st2)
{
    if(st1.length() != st2.length())
        return false;
    else
    {
        unordered_map<char,int> st1_map;
        unordered_map<char,int> st2_map;
        
        for(char ch:st1)
        {
            st1_map[ch]++;
        }
        
        for(char ch:st2)
        {
            st2_map[ch]++;
        }
        
        if(st1_map == st2_map)
            return true;
        else
            return false;
    }
}


int main()
{
    string str;
    int q;
    cin>>str;
    cin>>q;
    
    int n = str.length();
    
    string res = "";
    int ptr = 0;
    
    for(int i=0;i<q;i++)
    {
        char ch;
        int a;
        cin>>ch;
        cin>>a;
        
        if(ch == 'L')
        {
            ptr = (ptr+a)%n;
            res = res + str[ptr];
        }
        else
        {
            ptr = (((ptr-a)%n)+n)%n;
            res = res + str[ptr];
        }
    }
    
    int ftr = 0;
    int status = -1;
	while(ftr <= (n-q))
	{
		string stm = str.substr(ftr,q);
		ftr++;
		bool result = checkAnagram(stm,res);
		if(result)
		{
		    status = 1;
		    cout<<"YES"<<endl;
		    break;
		}
	}
	if(status == -1)
	    cout<<"NO"<<endl;
	    
	    
	return 0;
}
