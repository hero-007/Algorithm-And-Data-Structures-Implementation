#include <bits/stdc++.h>
using namespace std;

bool isSame(string s1,string s2,int x,int y)
{
    if(x>=0 && x<s1.length() && y>=0 && y<s2.length()){
        if(s1[x] == s2[y])
            return true;
    }
    return false;
}

int findMax(string s1,string s2,int m,int n,int **dp,int &max_len)
{
    if(m == 0 || n == 0)
        return 0;
    
    if(dp[m][n] != -1)
        return dp[m][n];
        
    int op1 = 0,op2 = 0,op3 = 0;
    op2 = findMax(s1,s2,m-1,n,dp,max_len);
    op3 = findMax(s1,s2,m,n-1,dp,max_len);
    
    if(s1[m-1] == s2[n-1])
    {
        op1 = 1 + findMax(s1,s2,m-1,n-1,dp,max_len);
        
        if(op1 > max_len)
            max_len = op1;
        
    }
    
    dp[m][n] = op1;
    
    return op1;
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++)
        {
            dp[i] = new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j] = -1;
        }
        string s1,s2;
        cin>>s1;
        cin>>s2;
        
        int max_len = 0;
        int result = findMax(s1,s2,m,n,dp,max_len);
        cout<<max_len<<endl;
    }
	return 0;
}
