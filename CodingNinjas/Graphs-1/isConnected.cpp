#include <bits/stdc++.h>
using namespace std;

bool isConnected(int **adj_matrix,int n,int st,bool *visited)
{
    queue<int> q;
    bool status = true;
    
    q.push(st);
    visited[st] = true;
    
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
                visited[i] = true;
            }
        }
            
         q.pop();   
    }
    
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            status = false;
            break;
        }
    }
    
    return status;
}

int main() {
    int n, e;
    cin >> n >> e;

    int **adj_matrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        adj_matrix[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    
    bool result = isConnected(adj_matrix,n,0,visited);
    
    if(result)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

  return 0;
}

