#include<bits/stdc++.h>
using namespace std;


int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int **dp = new int*[row];
    for(int i=0;i<row;i++)
        dp[i] = new int[col];
    
    
    int max_size = 0;
    for(int i=0;i<col;i++)
    {
        if(arr[0][i] == 0)
        {
            dp[0][i] = 1;
            max_size = 1;
        }
        else
        {
            dp[0][i] = 0;
        }
    }
    
    for(int j=0;j<row;j++)
    {
        if(arr[j][0] == 0)
        {
            dp[j][0] = 1;
            max_size = 1;
        }
        else
        {
            dp[j][0] = 0;
        }
    }
    
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            int a = dp[i-1][j-1];
            int b = dp[i-1][j];
            int c = dp[i][j-1];
            
            if(arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int siz = min(a,min(b,c));
                dp[i][j] = siz+1;
                
                if(dp[i][j] > max_size)
                    max_size = dp[i][j];
            }
        }
    }
    
    
    return max_size;
    
}



int main()
{
	int row,col;
	cin>>row>>col;
	
	int **arr = new int*[row];
	for(int i=0;i<row;i++)
		arr[i] = new int[col];
		
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>arr[i][j];
			
			
	int result = findMaxSquareWithAllZeros(arr,row,col);
	cout<<result<<endl;
	return 0;
}
