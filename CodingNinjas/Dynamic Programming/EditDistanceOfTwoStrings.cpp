/**
Edit Distance - Problem

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character

Note - Strings don't contain spaces

Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
Line 1 : Edit Distance value

Constraints
1<= m,n <= 20

Sample Input 1 :
abc
dc
Sample Output 1 :
2

**/
#include<bits/stdc++.h>
using namespace std;

int ed(string s1,string s2,int m,int n,int **dp)
{
     if(m == 0)
          return n;
    
    if(n == 0)
            return m;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    string st1 = s1.substr(1);
    string st2 = s2.substr(1);
    
    int res = -1;
    if(s1[0] == s2[0])
        res = ed(st1,st2,m-1,n-1,dp);
    else
    {
        int op1 = 1+ed(st1,st2,m-1,n-1,dp);  // replace;
        int op2 = 1+ed(st1,s2,m-1,n,dp);  // delete
        int op3 = 1+ed(s1,st2,m,n-1,dp); // insert
        
        res = min(op1,min(op2,op3));
    }
    
    dp[m][n] = res;
    return res;
}
    
int editDistance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++)
            dp[i][j] = -1;
    }
    
    
    int res = ed(s1,s2,m,n,dp);
    return res;
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}


