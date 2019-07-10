#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x,y;
    int weight;
};

bool isValid(int n,int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
        return true;
    return false;
}

int findMinPath(int kx,int ky,int tx,int ty,bool **visited,int n)
{
    int x[] = {-2,-2,-1,1,2,2,1,-1};
    int y[] = {-1,1,2,2,1,-1,-2,-2};
    
    Node st;
    st.x = tx;
    st.y = ty;
    st.weight = 0;
    
    if(kx == tx && ky == ty)
        return 0;
        
    visited[tx][ty] = true;
    
    queue<Node> q;
    q.push(st);
    
    while(!q.empty())
    {
        Node curr = q.front();
        q.pop();
        
        // explore all eight positions 
        for(int i=0;i<8;i++)
        {
            int nx = curr.x + x[i];
            int ny = curr.y + y[i];
            
            if(isValid(n,nx,ny) && visited[nx][ny] == false)
            {
                Node temp;
                temp.x = nx;
                temp.y = ny;
                temp.weight = curr.weight+1;
                visited[nx][ny] = true;
                q.push(temp);
                
                if(nx == kx && ny == ky)
                    return temp.weight;
            }
        }
    }
    
    return -1;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int kx,ky,tx,ty;
	    cin>>kx>>ky>>tx>>ty;
	    
	    bool **visited = new bool*[n+1];
	    for(int i=0;i<=n;i++)
	    {
	        visited[i] = new bool[n+1];
	        for(int j=0;j<=n;j++)
	            visited[i][j] = false;
	    }
	    
	    int minPath = findMinPath(kx,ky,tx,ty,visited,n);
	    cout<<minPath<<endl;
	    
	    for(int i=0;i<=n;i++)
	        delete []visited[i];
	}
    return 0;
}
