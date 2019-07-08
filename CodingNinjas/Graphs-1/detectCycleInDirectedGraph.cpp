{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool checkCycle(vector<int> adj[],bool *visited,bool *recStack,int st)
{
    visited[st] = true;
    recStack[st] = true;
    
    vector<int> temp = adj[st];
    for(int i=0;i<temp.size();i++)
    {
        int el = temp[i];
        
        // check if el is already in the recStack then return true - bcz the cycle exists
        if(recStack[el] == true)
            return true;
            
        if(visited[el] == false)
        {
            bool status = checkCycle(adj,visited,recStack,el);
            if(status)
                return true;
        }
    }
    
    recStack[st] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    
    for(int j=0;j<V;j++)
    {
        if(visited[j] == false)
        {
            bool status = checkCycle(adj,visited,recStack,j);
            if(status)
                return true;
        }
    }
    return false;
}
