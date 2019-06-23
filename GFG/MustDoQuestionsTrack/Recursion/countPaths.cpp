#include<bits/stdc++.h>
using namespace std;

bool isValid(int m,int n,int i,int j)
{
    if(i < m && j < n)
        return true;
    return false;
}

int countPaths(int m,int n,int i,int j)
{
    if(i == m-1 && j == n-1)
        return 1;
    
    bool checkRight = isValid(m,n,i,j+1);
    bool checkDown = isValid(m,n,i+1,j);

    int rightPath = 0,downPath = 0;
    if(checkRight)
        rightPath = countPaths(m,n,i,j+1);
    
    if(checkDown)
        downPath = countPaths(m,n,i+1,j);

    return rightPath+downPath;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int m,n;
        cin>>m>>n;

        int result = countPaths(m,n,0,0);
        cout<<result<<endl;
    }

    return 0;
}