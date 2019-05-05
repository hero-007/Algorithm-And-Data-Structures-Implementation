#include<bits/stdc++.h>
using namespace std;

#define NMAX 55
char cake[NMAX][NMAX];

bool checkValid(char cake[NMAX][NMAX],bool **visited,int n,int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n)
    {
        if(cake[i][j] == '1' && visited[i][j] == false)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

int findSize(char cake[NMAX][NMAX],bool **visited,int n,int i,int j)
{
   visited[i][j] = true;
    bool a = checkValid(cake,visited,n,i+1,j);
    bool b = checkValid(cake,visited,n,i-1,j);
    bool c = checkValid(cake,visited,n,i,j-1);
    bool d = checkValid(cake,visited,n,i,j+1);
    
    if(a==false && b==false && c==false && d==false)
    {
        return 1;
    }
    
    int s1=0,s2=0,s3=0,s4=0;
    
    if(a && visited[i+1][j] == false)
        s1 = findSize(cake,visited,n,i+1,j);
    
    if(b && visited[i-1][j] == false)
        s2 = findSize(cake,visited,n,i-1,j);
    
    if(c && visited[i][j-1] == false)
        s3 = findSize(cake,visited,n,i,j-1);
    
    if(d && visited[i][j+1] == false)
        s4 = findSize(cake,visited,n,i,j+1);
    
    return (s1+s2+s3+s4+1);
}

int solve(int n,char cake[NMAX][NMAX])
{
	int max_size = 0;
    bool **visited = new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = new bool[n];
        for(int j=0;j<n;j++)
        {
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j] == '1' && visited[i][j] == false)
            {
                int g = findSize(cake,visited,n,i,j);
                if(g > max_size){
                    max_size = g;
                }
            }
        }
    }
    
    return max_size;
}


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
