#include<bits/stdc++.h>
using namespace std;

void print_dfs(int **adj_matrix,bool *visited,int n,int st)
{
	cout<<st<<" ";
	visited[st] = true;
	
	for(int i=0;i<n;i++)
	{
		if(adj_matrix[st][i] == 1)
		{
			if(visited[i] == true)
				continue;
			
			print_dfs(adj_matrix,visited,n,i);
		}
	}
}

int main()
{
	int n,e; // n = number of vertices, e = number of edges
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter the number of edges : ";
	cin>>e;
	
	int **adj_matrix = new int* [n];
	for(int i=0;i<n;i++)
	{
		adj_matrix[i] = new int[n];
		for(int j=0;j<n;j++)
			adj_matrix[i][j] = 0;
	}
	
	
	cout<<"Enter the edges below : "<<endl;
	for(int k=0;k<e;k++)
	{
		int a,b;
		cin>>a>>b;
		
		adj_matrix[a][b] = 1;	
		adj_matrix[b][a] = 1;	// Since the graph is undirected graph
	}
	
	bool *visited = new bool[n];
	for(int l=0;l<n;l++)
		visited[l] = false;
	
	cout<<"DFS Traversal of the graph : ";
	print_dfs(adj_matrix,visited,n,0);
	cout<<endl;
	return 0;
}
