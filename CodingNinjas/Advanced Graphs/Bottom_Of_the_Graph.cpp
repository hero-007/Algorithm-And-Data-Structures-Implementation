#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >edges(5005);
vector<vector<int> >edgesT(5005);
vector<bool> visited(5005);

void dfs(int i,stack<int> &topo)
{
    visited[i] = true;
    for(int j=0;j<edges[i].size();j++)
    {
        int adjacent = edges[i][j];
        if(visited[adjacent] == false)
            dfs(adjacent,topo);
    }
    topo.push(i);
}

void dfs2(int start,unordered_set<int> *com)
{
    visited[start] = true;
    com->insert(start);
    
    for(int k=0;k<edgesT[start].size();k++)
    {
        int adj  = edgesT[start][k];
        if(visited[adj] == false)
        {
            dfs2(adj,com);
        }
    }
}

unordered_set<unordered_set<int>* >* getSCC(int n)
{

    unordered_set<unordered_set<int>* >* output = new unordered_set<unordered_set<int>*>();
    stack<int> topo;
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
            dfs(i,topo);
    }
    
    // clear the visited array
    for(int j=0;j<5005;j++)
        visited[j] = false;
    
    while(topo.size() != 0)
    {
        int start = topo.top();
        topo.pop();
        
        if(visited[start] == false)
        {
            unordered_set<int>* com = new unordered_set<int>();
            dfs2(start,com);
            output->insert(com);
        }
    }
    return output;
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
        
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a-1].push_back(b-1);
            edgesT[b-1].push_back(a-1);
        }
        
        for(int i=0;i<5005;i++)
        {
            visited[i] = false;
        }

        unordered_set<unordered_set<int>* >* scc = getSCC(n);

        unordered_map<int,int> component_map;    // this component map vertex to its component 
        unordered_set<unordered_set<int>* >::iterator it1 = scc->begin();
        
        int comp_number = 1;
        while(it1 != scc->end())
        {
            unordered_set<int>* sub = *it1;
            unordered_set<int>::iterator it2 = sub->begin();
            while(it2 != sub->end())
            {
                component_map[*it2] = comp_number;
                it2++;
            }
            comp_number++;
            it1++;
        }
        
        // Print the SCC if it is bottom of the graph
        unordered_set<unordered_set<int>* >::iterator it3 = scc->begin();
        set<int> s;
        while(it3 != scc->end())
        {
            unordered_set<int>* sub = *it3;
            unordered_set<int>::iterator it4 = sub->begin();
            unordered_set<int>::iterator temp_it = sub->begin();
            bool status = true;
            while(it4 != sub->end())
            {
                int v = *it4;
                vector<int> temp = edges[v];
                for(int j=0;j<temp.size();j++)
                {
                    int k = temp[j];
                    if(component_map[k] == component_map[v])
                        continue;
                    else
                    {
                        status = false;
                        break;
                    }
                }
                
                if(status == false)
                    break;
                it4++;
            }
            
            it3++;
            if(status == false)
                continue;
            else
            {
                // print the current SCC
                while(temp_it != sub->end())
                {
                    int pq = *temp_it+1;
                    s.insert(pq);
                    temp_it++;
                }
            }
        }
        set<int>::iterator pr=s.begin();
        while(pr!=s.end())
        {
            cout<<*pr<<" ";
            pr++;
        }
        cout<<endl;
        for(int i=0;i<5005;i++)
        {
            edges[i].clear();
            edgesT[i].clear();
        }
        
        delete scc;
    }
    
    return 0;
}
