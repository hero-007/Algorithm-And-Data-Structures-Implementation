#include <bits/stdc++.h>
using namespace std;

void print_bfs(int **arr,int n,int st)
{
	// Create a visited array and a queue
	queue<int> q;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
		
	// Push the starting vertex into the queue
	q.push(st);
	visited[st] = true;
	
    while(!q.empty())
    {
        int a = q.front();
        cout<<a<<" ";
        
        for(int i=0;i<n;i++)
        {
        	if(a == i)
        		continue;
        		
        	if(arr[a][i] == 1)
        	{
        		if(visited[i] == true)
        			continue;
        		else
        		{
        			q.push(i);
        			visited[i] = true;
				}
			}
		}
        q.pop();
    }
    return;
}


int main() {
    int n, e;
    cin >> n >> e;

 int **adj_matrix = new int* [n];
	for(int i=0;i<n;i++)
	{
		adj_matrix[i] = new int[n];
		for(int j=0;j<n;j++)
			adj_matrix[i][j] = 0;
	}
	
	
	for(int k=0;k<e;k++)
	{
		int a,b;
		cin>>a>>b;
		
		adj_matrix[a][b] = 1;	
		adj_matrix[b][a] = 1;	// Since the graph is undirected graph
	}
	
    
	print_bfs(adj_matrix,n,0);
	cout<<endl;
	return 0;
}

