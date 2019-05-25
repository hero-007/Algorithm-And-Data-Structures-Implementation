#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define siz 1000001

void fill_fac(int *fac)
{
	for(int i=2;i<siz;i++)
    {
        long temp = (long)fac[i-1] * i;
        int res = (int)(temp%mod);
        fac[i] = res;
    }
}

bool isValid(int x1,int y1,int x2,int y2)
{
    if(x2 == x1+2 && y2 == y1-1)
        return true;
    if(x2 == x1+1 && y2 == y1-2)
        return true;
    if(x2 == x1-1 && y2 == y1-2)
        return true;
    if(x2 == x1-2 && y2 == y1-1)
        return true;
    if(x2 == x1-2 && y2 == y1+1)
        return true;
    if(x2 == x1-1 && y2 == y1+2)
        return true;
    if(x2 == x1+1 && y2 == y1+2)
        return true;
    if(x2 == x1+2 && y2 == y1+1)
        return true;
    return false;
}

void singleConnectedComponent(vector<int> *adj_list,vector<int> &temp,bool *visited,int start)
{
    visited[start] = true;
    temp.push_back(start);
    
    vector<int> t = adj_list[start];
    for(int i=0;i<t.size();i++)
    {
        int el = t[i];
        if(visited[el] == false)
        {
            singleConnectedComponent(adj_list,temp,visited,el);
        }
    }
}

vector<vector<int> > getConnected(vector<int> *adj_list,int q)
{
    bool *visited = new bool[q];
    for(int i=0;i<q;i++)
        visited[i] = false;
    
    vector<vector<int> >output;
    for(int j=0;j<q;j++)
    {
        if(visited[j] == false)
        {
            vector<int> temp;
            singleConnectedComponent(adj_list,temp,visited,j);
            output.push_back(temp);
        }
    }
    
    delete []visited;
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
    cin>>t;
    
    int * fac = new int[siz];
    fac[0] = 1;
    fac[1] = 1;
    fill_fac(fac);
        
    while(t--)
    {
        int n,m,q;    // n - rows, m - columns, q - number of horses
        cin>>n>>m>>q;
        
        vector<pair<int,int> > horses(q);
        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            horses[i].first = a;
            horses[i].second = b;
        }
        
        // using the above vector generate a adj_list
        vector<int> *adj_list = new vector<int>[q];
        for(int i=0;i<q;i++)
        {
            pair<int,int> temp = horses[i];
            
            for(int j=i+1;j<q;j++)
            {
                
                pair<int,int> temp2 = horses[j];
                bool status = isValid(temp.first,temp.second,temp2.first,temp2.second);
                
                if(status)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        // after the completion of this code adj_list will be obtained
        // Now simply find all the connected components
        
        int result = 1;
        vector<vector<int> >output = getConnected(adj_list,q);
        int st = output.size();
        for(int kt=0;kt<st;kt++)
        {
            int temp = output[kt].size();
            int res = fac[temp];
            
            long temp_ = (long)result * res;
            result = (int)(temp_%mod);
        }
        cout<<result<<endl;
    }
    
	return 0;
}

