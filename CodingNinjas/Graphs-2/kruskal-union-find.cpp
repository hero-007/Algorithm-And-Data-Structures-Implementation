/**
Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

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

#include <bits/stdc++.h>
using namespace std;

struct Edge_Node{
    int v1;
    int v2;
    int w;
};

bool compare(Edge_Node e1,Edge_Node e2)
{
    return e1.w < e2.w;
}

int topMostParent(int v,int *parent)
{
    while(parent[v]!=v)
    {
        v = parent[v];
    }
    
    return v;
}

bool checkCycle(Edge_Node e,int *parent)
{
    int a = topMostParent(e.v1,parent);
    int b = topMostParent(e.v2,parent);
    
    if(a == b)
    {
        return false;
    }
    
    parent[b] = a;
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    Edge_Node edge[e];
    Edge_Node result[n-1];
    
    for(int i=0;i<e;i++)
    {
        cin>>edge[i].v1;
        cin>>edge[i].v2;
        cin>>edge[i].w;
    }
    
    sort(edge,edge+e,compare);
    
    int *parent = new int[n];
    for(int i=0;i<n;i++)
        parent[i] = i;
    
    int count = 0;
    int ptr = 0;
    int result_ptr = 0;
    
    while(count < n-1)
    {
        bool if_add = checkCycle(edge[ptr],parent);
        
        if(if_add)
        {
            result[result_ptr] = edge[ptr];
            result_ptr++;
            count++;
        }
        ptr++;
    }
    
    
    for(int i=0;i<n-1;i++)
    {
        Edge_Node e = edge[i];
        int a,b;
        if(e.v1 < e.v2)
        {
            a = e.v1;
            b = e.v2;
        }
        else
        {
            a = e.v2;
            b = e.v1;
        }
        
        cout<<a<<" "<<b<<" "<<e.w<<endl;
    }
    return 0;
}

