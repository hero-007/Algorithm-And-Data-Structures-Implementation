#include<bits/stdc++.h>
using namespace std;

void getSingleComponent(vector<int> *arr, bool *visited, vector<int> &temp, int n, int start)
{
    visited[start] = true;
    temp.push_back(start);
    
    vector<int> t = arr[start];
    for(int k=0;k<t.size();k++)
    {
        int g = t[k];
        if(!visited[g])
        {
            getSingleComponent(arr,visited,temp,n,g);
        }
    }
}

vector<vector<int> > getComponent(vector<int> *arr,int n)
{
    vector<vector<int> >output;
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            vector<int> temp;
            getSingleComponent(arr,visited,temp,n,i);
            output.push_back(temp);
        }
    }
    
    delete []visited;
    
    return output;
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
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
        }
        
        long long * val = new long long[n];
        for(int j=0;j<n;j++)
        {
            long long tk;
            
            cin>>tk;
            val[j] = tk;
        }
        
        vector<vector<int> >result = getComponent(arr,n);
        long long max_ban = 0;
        
        for(int i=0;i<result.size();i++)
        {
            vector<int> temp = result[i];
            long long sum = 0;
            for(int j=0;j<temp.size();j++)
            {
                sum += val[temp[j]];
            }
            
            if(sum > max_ban)
                max_ban = sum;
        }
        
        cout<<max_ban<<"\n";
        
        delete []arr;
        delete []val;
    }
    
	return 0;
}

