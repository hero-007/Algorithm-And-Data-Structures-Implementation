// Not yet Working giving wrong answer


#include<bits/stdc++.h>
using namespace std;

/**
State mapping 
1 - none 
2 - any
3 - some
**/

struct edgeNode{
    int v1;
    int v2;
    int w;
    int id;
};

bool compare(edgeNode e1,edgeNode e2)
{
    return (e1.w < e2.w);
}

int topMostParent(int v,int *parent)
{
    while(parent[v]!=v)
    {
        v = parent[v];
    }
    return v;
}

bool checkIfPossible(edgeNode e,int *parent)
{
    int a = topMostParent(e.v1,parent);
    int b = topMostParent(e.v2,parent);
    
    if(a == b)
        return false;
    parent[b] = a;
    return true;
}

void dfs(int **adj_matrix,bool *visited,int n,int start)
{
    visited[start] = true;
    for(int i=0;i<n;i++)
    {
        if(start == i)
            continue;
        
        if(visited[i] == false && adj_matrix[start][i] > 0)
            dfs(adj_matrix,visited,n,i);
    }
}

bool ifBridgeEdge(edgeNode currentEdge,int **adj_matrix,int n)
{
    // this return true of the given edge is a bridge edge otherwise it returns false
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    
    // remove the current edge from the graph and check whether it is still connected or not 
    int v1 = currentEdge.v1;
    int v2 = currentEdge.v2;
    adj_matrix[v1][v2] = 0;
    adj_matrix[v2][v1] = 0;
    
    dfs(adj_matrix,visited,n,0);
    
    bool isConnected = true;
    for(int j=0;j<n;j++)
    {
        if(visited[j] == false)
        {
            isConnected = false;
            break;
        }
    }
    
    // add the removed edge back 
    adj_matrix[v1][v2] = currentEdge.w;
    adj_matrix[v2][v1] = currentEdge.w;
    
    if(isConnected == false) // this means that removed edge was a bridge
        return true;
    return false;
}

int main()
{
	int n,m;
    cin>>n>>m;
    
    edgeNode edge[m];
    int status[m];
    
    // use a hash map for checking whether a given edge is unique or not
    unordered_map<int,int>edge_count;
    int **adj_matrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        adj_matrix[i] = new int[n];
        for(int j=0;j<n;j++)
            adj_matrix[i][j] = 0;
    }
    
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i].v1 = a-1;
        edge[i].v2 = b-1;
        edge[i].w = c;
        edge[i].id = i;
        
        edge_count[c]++;
        
        adj_matrix[a-1][b-1] = c;
        adj_matrix[b-1][a-1] = c;
    }
    
    sort(edge,edge+m,compare);
    
    int *parent = new int[n];
    for(int i=0;i<n;i++)
        parent[i] = i;
    

    int ptr = 0;
    
    while(ptr < m)
    {
        edgeNode temp = edge[ptr];
        int temp_w = temp.w;
        int temp_id = temp.id;
        
        if(edge_count[temp_w] > 1)
        {
            // this implies that this edge is not unique
            bool check_cycle = checkIfPossible(edge[ptr],parent);
            if(!check_cycle)
            {
                status[temp_id] = 1; // 1 -> None
            }
            else
            {
                bool check_bridge = ifBridgeEdge(edge[ptr],adj_matrix,n);
                if(check_bridge)
                {
                    status[temp_id] = 2; // 2 -> any
                }
                else
                {
                    status[temp_id] = 3; // 3 -> at least one
                }
            }
            
        }
        else
        {
            // this implies that the edge is unique
            // if the edge is unique then it should be processed seprately 
            
            bool if_possible = checkIfPossible(edge[ptr],parent);
            if(if_possible)
            {
                status[temp_id] = 2; // 2 -> any
            }
            else
            {
                status[temp_id] = 1; // 1 -> none
            }
        }
        
        ptr++;
    }
    
    
    // print the status array 
    for(int i=0;i<m;i++)
    {
        if(status[i] == 1)
            cout<<"none";
        else if(status[i] == 2)
            cout<<"any";
        else 
            cout<<"at least one";
        cout<<endl;
    }
    
	return 0;
}

