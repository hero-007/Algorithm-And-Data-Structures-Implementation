#include<bits/stdc++.h>
using namespace std;

void print_bfs(int **adj_matrix,int n,int st,bool *visited)
{
	queue<int> q;
	q.push(st);
	
	visited[st] = true;
	
	while(!q.empty())
	{
		int a = q.front();
		cout<<a<<" ";
		
		for(int j=0;j<n;j++)
		{
			if(a == j)
				continue;
				
			if(adj_matrix[a][j] == 1)
			{
				if(visited[j] == true)
					continue;
				else
				{
					q.push(j);
					visited[j] = true;
				}
			}
		}
		
		q.pop();
	}
}

void bfs_traverse(int **adj_matrix,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	for(int j=0;j<n;j++)
	{
		if(!visited[j])
			print_bfs(adj_matrix,n,j,visited);
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
	cout<<"BFS TRAVERSAL : ";
	bfs_traverse(adj_matrix,n);
	cout<<endl;
	
	return 0;
}
