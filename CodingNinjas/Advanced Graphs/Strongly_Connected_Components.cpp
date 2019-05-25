#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges,int start,stack<int> &finishedVertices,unordered_set<int> &visited)
{
	// The motive of this DFS is to fill the stack 
	visited.insert(start);
	
	vector<int> t = edges[start];
	for(int i=0;i<t.size();i++)
	{
		int a = t[i];
		if(visited.count(a) == 0 )
		{
			dfs(edges,a,finishedVertices,visited);
		}
	}
	
	finishedVertices.push(start);
}

void dfs2(vector<int> *edgesT,int start,unordered_set<int> &visited,unordered_set<int> *component)
{
	visited.insert(start);
	component->insert(start);
	
	vector<int> t = edgesT[start];
	for(int i=0;i<t.size();i++)
	{
		int a = t[i];
		if(visited.count(a) == 0)
		{
			dfs2(edgesT,a,visited,component);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<int> *edges,vector<int> *edgesT,int n)
{
	unordered_set<int> visited;
	stack<int> finishedVertices;
	unordered_set<unordered_set<int>*> *output = new unordered_set<unordered_set<int>*>();
	// Step 1 - fill this stack using edges by applying DFS
	for(int i=0;i<n;i++)
	{
		if(visited.count(i) == 0)
		{
			dfs(edges,i,finishedVertices,visited);
		}
	}
	
	visited.clear();
	// Step 2 - use the stack and edgesT to find the Strongly Connected Components by applying DFS again
	while(finishedVertices.size() != 0)
	{
		int start = finishedVertices.top();
		finishedVertices.pop();
		if(visited.count(start) == 0)
		{
			unordered_set<int> *component = new unordered_set<int>();
			dfs2(edgesT,start,visited,component);
			output->insert(component);
		}
	}
	
	return output;
}

int main()
{
	int n,m; // n - number of vertices | m - number of edges
	cin>>n>>m;
	
	vector<int> *edges = new vector<int>[n];
	vector<int> *edgesT = new vector<int>[n];
	
	for(int i=0;i<m;i++)
	{
		int a,b;	// directed edge between a -> b
		cin>>a>>b;
		
		edges[a-1].push_back(b-1);
		edgesT[b-1].push_back(a-1);
	}
	
	unordered_set<unordered_set<int>*> *scc = getSCC(edges,edgesT,n);
	
	// use iterator to print the  elements of the scc
	unordered_set<unordered_set<int>*>::iterator it = scc->begin();
	while(it != scc->end())
	{
		unordered_set<int> *sc = *it;
		unordered_set<int>::iterator itx = sc->begin();
		while(itx != sc->end())
		{
			cout<<*itx+1<<" ";
			itx++;
		}
		cout<<endl;
		delete sc;
		it++;
	}
	delete scc;
	delete []edges;
	delete []edgesT;
	return 0;
}
