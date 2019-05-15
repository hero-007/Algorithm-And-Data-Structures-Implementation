/**
Dijkstra's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.

Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
In different lines, ith vertex number and its distance from source (separated by space)

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 0
1 3
2 4
3 5

**/
#include <bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int *distance,int n)
{
    // returns the unvisited vertex, which has the minimum distance
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void singleSourceShortestPath(int **arr,int n)
{
    /**
    Create a distance and visited array
    **/
    
    int *distance = new int[n];
    bool *visited = new bool[n];
    
    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    
   
    
    for(int i=0;i<n-1;i++)
    {
        int currentSource = getMinVertex(visited,distance,n);
        visited[currentSource] = true;
        // find all the unvisited neighbour of the currentSource and then update the distance if possible
        for(int j=0;j<n;j++)
        {
            if(j == currentSource)
                continue;
            
            if(arr[currentSource][j] && visited[j] == false)
            {
                int currD = distance[currentSource]+arr[currentSource][j];
                if(distance[j] > currD)
                {
                    distance[j] = currD;
                }
            }
        }
        
    }
    
    // Print the distance between each node and the source
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    
    delete []visited;
    delete []distance;
}

int main()
{
    int n,e;
    cin >> n >> e;
    
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }
    
    // Fill the adjacency matrix 
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        arr[u][v] = w;
        arr[v][u] = w;
    }
    
    singleSourceShortestPath(arr,n);

    return 0;
}

