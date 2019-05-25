#include<bits/stdc++.h>
using namespace std;

int getPath(vector<int> *arr,int st,int ed,bool *visited,int n)
{
    int *level = new int[n];
    queue<int> q;
    
    int found = -1;
    
    q.push(st);
    visited[st] = true;
    level[st] = 0;
    
    while(!q.empty())
    {
        int a = q.front();
        vector<int> temp = arr[a];
        
        for(int i=0;i<temp.size();i++)
        {
            
            int it = temp[i];
            
            if(!visited[it])
            {
                q.push(it);
                visited[it] = true;
                level[it] = level[a]+1;
                
                if(it == ed)
                {
                    found = 1;
                    break;
                }
            }
        }
        
        if(found == 1)
            break;
        
        q.pop();
    }
    
    
    return level[ed];
}

int main()
{
	int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector<int> *arr = new vector<int>[n];
        
        for(int j=0;j<m;j++)
        {
            int a,b;
            cin>>a>>b;
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
        }
        
        bool *visited = new bool[n];
        for(int k=0;k<n;k++)
            visited[k] = false;
        
        int a =getPath(arr,0,n-1,visited,n);
        
        cout<<a<<"\n";
        
        
        
        delete []visited;
        
    }
	return 0;
}

