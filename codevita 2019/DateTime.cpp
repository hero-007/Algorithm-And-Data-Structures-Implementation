#include<bits/stdc++.h>
using namespace std;

int m1 = -1,m2 = -1;
int d1 = -1,d2 = -1;
int h1 = -1,h2 = -1;
int min1 = -1,min2 = -1;

bool getDateTime(unordered_map<int,int> &mp,int pass_num)
{
    // base case
    if(pass_num >= 5)
        return true;
    
    int Ulimit = 0;
    int Llimit = 0;
    
    if(pass_num == 1)
    {
        Ulimit = 12;
        Llimit = 1;
        
    }
    else if(pass_num == 2)
    {
        int month = (m1*10) + m2;
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        Ulimit = 31;
        else if(month == 2)
        Ulimit = 28;
      	else
        Ulimit = 30;
        
        Llimit = 1;
    }
    else if(pass_num == 3)
    {
        Ulimit = 23;
        Llimit = 0;
    }
    else 
    {
        Ulimit = 59;
        Llimit = 0;
        
    }
    
    
    for(int j=Ulimit;j>=Llimit;j--)
    {
        int a = j;
        int k1 = a%10;
        if(mp[k1] == 0)
            continue;
        a = a/10;
        int k2 = a%10;
        if(mp[k2] == 0)
            continue;
            
        mp[k1] = mp[k1] - 1;
        mp[k2] = mp[k2] - 1;
        
        
        bool res = getDateTime(mp,pass_num+1);
        
        if(res)
        {
            if(pass_num ==  1)
            {
                m1 = k2;
                m2 = k1;
            }
            else if(pass_num == 2)
            {
                d1 = k2;
                d2 = k1;
            }
            else if(pass_num == 3)
            {
                h1 = k2;
                h2 = k1;
            }
            else
            {
                min1 = k2;
                min2 = k1;
            }
            
            return true;
        }
        else
        {
          mp[k1] = mp[k1] + 1;
          mp[k2] = mp[k2] + 1;
        }
      	
    }
    
    return false;
}

int main()
{
    string stn;
    cin>>stn;
    
    int l = stn.length();
    unordered_map<int,int> mp;
    
    for(int i=0;i<l;i++)
    {
        char ch = stn[i];
        if(ch == ',')
            continue;
        
        int d = int(ch) - 48;
        mp[d]++;
    }
    
    bool result = getDateTime(mp,1);
    if(result)
        cout<<m1<<m2<<"/"<<d1<<d2<<" "<<h1<<h2<<":"<<min1<<min2;
    else
        cout<<0;
    return 0;
}
