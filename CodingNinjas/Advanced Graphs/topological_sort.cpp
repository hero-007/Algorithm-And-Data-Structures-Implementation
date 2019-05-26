/**
Topological sort can be applied on Directed Acyclic Graph
It has numerous number of applications like in
1 - build systems 
2 - pre-requistes job scheduling
3 - Kosaraju's Algorithm
**/
#include<bits/stdc++.h>
using namespace std;

void fill_Stack(vector<int>*edges,vector<bool> &visited,stack<int> &topo,int start)
{
	visited[start] = true;
	
	for(int i=0;i<edges[start].size();i++)
	{
		int adj = edges[start][i];
		if(visited[adj] == false)
		{
			fill_Stack(edges,visited,topo,adj);
		}
	}
	topo.push(start);
}

void Topological_Sort(vector<int>*edges,int n)
{
	vector<bool> visited(n);
	for(int i=0;i<n;i++)
		visited[i] = false;
		
	stack<int> topo;
	
	//fill the stack 
	for(int i=0;i<n;i++)
	{
		if(visited[i] == false)
		{
			fill_Stack(edges,visited,topo,i);
		}
	}
	
	cout<<"Topological Sort Order : ";
	// stack contain the vertices in the Topological Sort
	while(topo.size()!=0)
	{
		int a = topo.top();
		topo.pop();
		cout<<a+1<<" ";
	}
	cout<<endl;
}


int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int>* edges = new vector<int>[n];
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		edges[a-1].push_back(b-1);
	}
	
	Topological_Sort(edges,n);
	cout<<endl;
	
	delete []edges;
	return 0;
}
