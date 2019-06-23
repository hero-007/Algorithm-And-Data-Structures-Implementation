#include<bits/stdc++.h>
using namespace std;

bool isValid(int **arr,bool **visited,int n,int m,int x,int y,int k,int val)
{
    if(x < n && x >= 0 && y < m && y >= 0)
    {
        if(visited[x][y] == false && arr[x][y] == val)
            return true;
        return false;
    }
    return false;
}

void floodFill(int **arr,bool **visited,int n,int m,int x,int y,int k,int val)
{
    arr[x][y] = k;
    visited[x][y] = true;
    
    bool isValidTop = false,isValidRight = false,isValidDown = false,isValidLeft = false;
	
    isValidTop = isValid(arr,visited,n,m,x-1,y,k,val);
    
    isValidRight = isValid(arr,visited,n,m,x,y+1,k,val);
    
    isValidDown = isValid(arr,visited,n,m,x+1,y,k,val);
   
    isValidLeft = isValid(arr,visited,n,m,x,y-1,k,val);
	
    if(!isValidTop && !isValidRight && !isValidDown && !isValidLeft)
        return;
	
    if(isValidTop && isValid(arr,visited,n,m,x-1,y,k,val))
    {
       floodFill(arr,visited,n,m,x-1,y,k,val);
    }

    if(isValidRight && isValid(arr,visited,n,m,x,y+1,k,val))
    {
       floodFill(arr,visited,n,m,x,y+1,k,val);
    }

    if(isValidDown && isValid(arr,visited,n,m,x+1,y,k,val))
    {
       floodFill(arr,visited,n,m,x+1,y,k,val);
    }

    if(isValidLeft && isValid(arr,visited,n,m,x,y-1,k,val))
    {
       floodFill(arr,visited,n,m,x,y-1,k,val);
    }
	
	return;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int **arr = new int*[n];
        bool **visited = new bool*[n];
        for(int j=0;j<n;j++)
        {
            arr[j] = new int[m];
            visited[j] = new bool[m];
            for(int i=0;i<m;i++)
            {
                int a;
                cin>>a;
                arr[j][i] = a;
                visited[j][i] = false;
            }
        }
		
        int x,y,k;
        cin>>x>>y>>k;
        
        int val = arr[x][y];
       
        floodFill(arr,visited,n,m,x,y,k,val);

        // Print the output array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            delete []arr[i];
            delete []visited[i];
        }
    }
    return 0;
}
