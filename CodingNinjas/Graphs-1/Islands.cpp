/**
Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.

Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N

Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :
The count the number of connected groups of islands

Sample Input :
2 1
1
2

Sample Output :
1 

**/
#include<bits/stdc++.h>
using namespace std;

void countConnected(int **arr, int n,int st,bool *visited)
{
    queue<int> q;
    q.push(st);
    
    visited[st] = true;
    while(!q.empty())
    {
        int a = q.front();
        
        for(int j=0;j<n;j++)
        {
            if(a == j)
                continue;
            
            if(arr[a][j] == 1 && !visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }
        
        q.pop();
    }
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **adj_matrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        adj_matrix[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        int a = u[i]-1;
        int b = v[i]-1;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    int count_connected_components = 0;
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    
    for(int j=0;j<n;j++)
    {
        if(visited[j] == false)
        {
            count_connected_components++;
            countConnected(adj_matrix,n,j,visited);
            
        }
    }
    
    return count_connected_components;
}
