/**
Code : All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
Different components in new line

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2

**/
#include <bits/stdc++.h>
using namespace std;

void connectedTraverse(int **arr,int n,int st,bool *visited,vector<int> &temp)
{
    temp.push_back(st);
    visited[st] = true;
    
    for(int i=0;i<n;i++)
    {
        if(i == st)
            continue;
        
        if(arr[st][i] == 1 && visited[i] == false)
        {
            connectedTraverse(arr,n,i,visited,temp);
        }
    }
}

vector<vector<int> > getConnectedComponents(int **adj_matrix,int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    
    vector<vector<int> >result;
    
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            vector<int> temp;
            connectedTraverse(adj_matrix,n,i,visited,temp);
            sort(temp.begin(),temp.end());
            result.push_back(temp);
        }
    }
    
    return result;
}

int main()
{
    int n,e;
    cin >> n >> e;
    
    int **adj_matrix = new int*[n];
    for(int j=0;j<n;j++){
        adj_matrix[j] = new int[n];
        for(int i=0;i<n;i++)
        {
            adj_matrix[j][i] = 0;
        }
    }
    
    for(int k=0;k<e;k++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
  
    vector<vector<int> > result = getConnectedComponents(adj_matrix,n);
    
    for(int it = 0;it<result.size();it++)
    {
        vector<int> temp = result[it];
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    
  return 0;
}

