#include <bits/stdc++.h>
using namespace std;

bool hasPathBFS(int **arr,int n,int st,int ed)
{
    queue<int> q;
    q.push(st);
    
    bool *visited = new bool[n];
    for(int j=0;j<n;j++)
        visited[j] = false;

    visited[st] = true;
    
    if(arr[st][ed] == 1)
        return true;
    
    while(!q.empty())
    {
        int a = q.front();
        
        if(a == ed)
            return true;
        
        for(int i=0;i<n;i++)
        {
            if(i == a)
                continue;
            if(arr[a][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
        
        q.pop();
    }
    
    return false;
}


int main() {
    int n, e;
    cin >> n >> e;
    
    int **adj_matrix = new int*[n];
    for(int i=0;i<n;i++){
        adj_matrix[i] = new int[n];
        for(int j=0;j<n;j++)
            adj_matrix[i][j] = 0;
    }
    
    for(int k=0;k<e;k++)
    {
        int a,b;
        cin>>a>>b;
        
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    int st,ed;
    cin>>st>>ed;
    
    bool result = hasPathBFS(adj_matrix,n,st,ed);
    
    if(result)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}

