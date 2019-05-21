// Write a program to generate all the connected components using adjacency list

#include<bits/stdc++.h>
using namespace std;

void singleConnectedComponent(vector<vector<int> >adj_list,vector<int> &temp,bool *visited,int start)
{
	visited[start] = true;
	temp.push_back(start);
	
	vector<int> t = adj_list[start];
	for(int i=0;i<t.size();i++)
	{
		int a = t[i];
		if(visited[a] == true )
			continue;
			
		singleConnectedComponent(adj_list,temp,visited,a);
	}
}

vector<vector<int> > getConnectedComponents(vector<vector<int> >adj_list,int n)
{
	vector<vector<int> >output;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	for(int j=0;j<n;j++)
	{
		if(visited[j] == false)
		{	
		vector<int> temp;
		singleConnectedComponent(adj_list,temp,visited,j);
		output.push_back(temp);
		}
	}
	
	delete []visited;
	return output;
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<vector<int> > adj_list(n);
	vector<int> value;
	for(int k=0;k<n;k++)
	{
		int b;
		cin>>b;
		value.push_back(b);
	}
	
	
	
	
	// create the adjacency list 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		
		adj_list[a-1].push_back(b-1);
		adj_list[b-1].push_back(a-1);
	}
	
	vector<vector<int> > output = getConnectedComponents(adj_list,n);
	
	// printing the content of output vector

	int l = output.size();
	
	for(int i=0;i<l;i++)
	{
		vector<int> tk = output[i];
		for(int j=0;j<tk.size();j++)
			cout<<tk[j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
