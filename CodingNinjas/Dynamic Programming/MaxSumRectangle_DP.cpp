#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    // n  = number of rows
    // m = number of columns
    cin>>n>>m;
    
    int arr[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    
    int maxSum = INT_MIN;
    for(int i=0;i<m;i++)
    {
        int left = i;
        for(int j=i+1;j<m;j++)
        {
            int right = j;
            
            int *temp = new int[n];
            memset(temp,0,sizeof(int)*n);
            
            for(int k=left;k<=right;k++)
            {
                for(int l=0;l<n;l++)
                {
                    temp[l] += arr[l][k];
                }
                
                int max_possible = INT_MIN;
                int current_max = 0;
                for(int r=0;r<n;r++)
                {
                    current_max += temp[r];
                     
                    if(current_max > max_possible)
                        max_possible = current_max;
                    
                    if(current_max <= 0)
                        current_max = 0;
                }
                
                if(max_possible > maxSum)
                    maxSum = max_possible;
            }
            
            delete []temp;
        }
    }
    
    cout<<maxSum<<endl;
    return 0;
}

