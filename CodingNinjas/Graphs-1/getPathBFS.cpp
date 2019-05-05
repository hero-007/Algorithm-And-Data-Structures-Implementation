#include <bits/stdc++.h>
using namespace std;

vector<int> getPathBFS(int **adj_matrix,int st,int ed,int n,bool *visited)
{
    unordered_map<int,int> vertex_map;
    queue<int> q;
    vector<int> result;
    
    if(st == ed)
    {
        result.push_back(st);
        return result;
    }
    
    q.push(st);
    visited[st] = true;
    
    int found = -1;
    
    while(!q.empty())
    {
        int a = q.front();
        
        for(int i=0;i<n;i++)
        {
            if(i == a)
                continue;
            
            if(adj_matrix[a][i] == 1 && visited[i] == false)
            {
                q.push(i);
                vertex_map[i] = a;
                visited[i] = true;
                
                if(i == ed)
                {
                    found = 1;    // path to destination vertex has been found
                    break;
                }
            }
        }
        
        if(found == 1)
            break;
        
        q.pop();
    }
    
    // check if the queue is empty - path not found other wise path is found
    if(!q.empty())
    {
        int temp_st = ed;
        while(temp_st != st)
        {
            result.push_back(temp_st);
            temp_st = vertex_map[temp_st];
        }
        result.push_back(st);
    }
    
    return result;
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
    
    vector<int> result = getPathBFS(adj_matrix,sou,des,n,visited);
    
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    
    return 0;
}

