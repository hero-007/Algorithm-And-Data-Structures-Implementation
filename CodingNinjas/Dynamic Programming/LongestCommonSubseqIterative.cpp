#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    
    int m = s1.length();
    int n = s2.length();
    
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
    }
    
    // fill first row with all 0s
    for(int i=0;i<=n;i++)
        dp[0][i] = 0;
    
    // fill first column with all 0s
    for(int j=0;j<=m;j++)
            dp[j][0] = 0;
    
    // now fill the entire dp array
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i] == s2[n-j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
    }
    
    int res = dp[m][n];
    for(int k=0;k<=m;k++)
        delete []dp[k];
    
    return res;
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << lcs(s1,s2) << endl;

}

