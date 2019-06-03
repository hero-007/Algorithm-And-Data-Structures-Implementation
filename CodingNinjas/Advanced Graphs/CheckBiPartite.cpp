#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<int>* edges,int n)
{
    unordered_set<int> sets[2];
    vector<int> pending;
    
    // take 0 as the first node and start the process
    sets[0].insert(0);
    pending.push_back(0);
    
    while(pending.size()!=0)
    {
        int current = pending.back();
        pending.pop_back();
        
        int current_set = (sets[0].count(current) > 0)?0:1;
        
        for(int i=0;i<edges[current].size();i++)
        {
            int neighbor = edges[current][i];
            
            if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0)
            {
                // neighbor has to be inserted into the opposite set as that of the current element 
                sets[1-current_set].insert(neighbor);
                pending.push_back(neighbor);
            }
            else if(sets[current_set].count(neighbor) > 0)
            {
                // neighbor is in same set as current so the given Graph is not bi-partite
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    while(true)
    {
        int n;
        cin>>n;
        
        if(n == 0)
            break;
            
        int e;
        cin>>e;
        
        vector<int> *edges = new vector<int>[n];
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        bool result = checkBipartite(edges,n);
        
        if(result == true)
            cout<<"Graph is BiPartite"<<endl;
        else 
            cout<<"Graph is not BiPartite"<<endl;
            
    delete []edges;
    }
    
    return 0;
}
