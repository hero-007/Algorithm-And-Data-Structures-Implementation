#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFS(int** adj_matrix,int st,int ed,int n,bool *visited)
{
    if(st == ed)
    {
        visited[st] = true;
        vector<int> temp;
        temp.push_back(st);
        return temp;
    }
    
    visited[st] = true;
    vector<int> path_result;
    
    for(int i=0;i<n;i++)
    {
        if(i == st)
            continue;
        
        if(adj_matrix[st][i] == 1 && visited[i] == false)
        {
            path_result = getPathDFS(adj_matrix,i,ed,n,visited);
                
            if(path_result.size() == 0)
            {
                continue;
            }
            else
            {
                path_result.push_back(st);
                return path_result;
            }
        }
    }
    
    return path_result;
}

int main()
{
    int n, e, sou, des;
    cin >>n>>e;

    int **adj_matrix = new int* [n];
    for(int i=0;i<n;i++)
	{
		adj_matrix[i] = new int[n];
		for(int j=0;j<n;j++)
			adj_matrix[i][j] = 0;
	}
    
    for(int j=0;j<e;j++)
    {
        int a,b;
        cin>>a>>b;
        
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    cin>>sou>>des;
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    
    vector<int> result = getPathDFS(adj_matrix,sou,des,n,visited);
    
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    
    return 0;
}

