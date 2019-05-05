#include<bits/stdc++.h>
using namespace std;

void print_dfs(int **adj_matrix,int n,bool *visited,int st)
{
	cout<<st<<" ";
	visited[st] = true;
	
	for(int i=0;i<n;i++)
	{
		if(st == i)
			continue;
			
		if(adj_matrix[st][i] == 1)
		{
			if(visited[i] == true)
				continue;
			print_dfs(adj_matrix,n,visited,i);
		}
	}
}

void dfs_traverse(int **adj_matrix,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
		
	for(int i=0;i<n;i++)
	{
		if(visited[i] == true)
			continue;
		else
			print_dfs(adj_matrix,n,visited,i);
	}
}


int main()
{
	int n,e;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter the number of edges : ";
	cin>>e;
	
	int **adj_matrix = new int* [n];
	for(int i=0;i<n;i++){
		adj_matrix[i] = new int[n];
		for(int j=0;j<n;j++)
			adj_matrix[i][j] = 0;
	}
		
	
	cout<<"Enter the edge pair below : "<<endl;
	for(int i = 0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj_matrix[a][b] = 1;
		adj_matrix[b][a] = 1;
	}
	
	cout<<endl;
	cout<<"DFS TRAVERSAL : ";
	dfs_traverse(adj_matrix,n);
	cout<<endl;
	
	return 0;
}
