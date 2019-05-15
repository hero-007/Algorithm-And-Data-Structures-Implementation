/**
Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.

For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.

2. Print V-1 edges in above format in different lines.

Note : Order of different edges doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
1 2 1
0 1 3
0 3 5

**/

#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int *weight,bool *visited,int n)
{
    int minVertex = -1;
    
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false && (minVertex == -1 || weight[minVertex] > weight[i]))
        {
            minVertex = i;
        }
    }
    
    return minVertex;
}

void primsMST(int **arr, int n)
{
    // n = number of verticies
    
    // create weight and parent array 
    int *weight = new int[n];
    int *parent = new int[n];
    bool *visited = new bool[n];
    
    for(int i=0;i<n;i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[0] = 0;
    parent[0] = -1;
    
    for(int i=0;i<n-1;i++)
    {
        int minVertex = getMinVertex(weight,visited,n); // get the unvisited vertex with minimum weight
        visited[minVertex] = true;
        
        // Now explore all the neighbours of this minVertex and update their weight and parent if possible
        for(int j=0;j<n;j++)
        {
            if(j == minVertex)
                continue;
            
            if(arr[minVertex][j] != 0 && !visited[j])
            {
                if(weight[j] > arr[minVertex][j])
                {
                    weight[j] = arr[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    // Now print the final MST

    for(int i=1;i<n;i++)
    {
        int a = i;
        int b = parent[i];
        
        if(a < b)
        {
            cout<<a<<" "<<b<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<b<<" "<<a<<" "<<weight[i]<<endl;
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        arr[u][v] = w;
        arr[v][u] = w;
    }
    
    primsMST(arr,n);
    
    return 0;
}
