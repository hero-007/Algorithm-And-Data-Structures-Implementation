#include<bits/stdc++.h>
using namespace std;

int solMaze[20][20];
bool isPossible(int maze[][20],int n,int r,int c)
{
    /*
    This function will check 3 comstraints -
    1 - if the current position is a block 
    2 - if the current position is out of the grid 
    3 - if the current postion is already occupied 
    */
    
    if(maze[r][c] == 0)
        return false;
    else if((r == -1 || r == n) || (c == -1 || c == n))
        return false;
    else if(solMaze[r][c] == 1)
        return false;
    else
        return true;
}

void moveRatInMaze(int maze[][20],int n,int r,int c)
{
    if(r == n-1 && c == n-1)
    {
        // we've discovered a possible path for the rat
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<solMaze[i][j]<<" ";
        cout<<endl;
        return;
    }
    
    bool moveTop = isPossible(maze,n,r-1,c);
    bool moveLeft = isPossible(maze,n,r,c-1);
    bool moveRight = isPossible(maze,n,r,c+1);
    bool moveDown = isPossible(maze,n,r+1,c);
    
    if(moveTop)
    {
        solMaze[r-1][c] = 1;
        moveRatInMaze(maze,n,r-1,c);
        solMaze[r-1][c] = 0;
    }
    
    if(moveLeft)
    {
        solMaze[r][c-1] = 1;
        moveRatInMaze(maze,n,r,c-1);
        solMaze[r][c-1] = 0;
    }
    
    if(moveRight)
    {
        solMaze[r][c+1] = 1;
        moveRatInMaze(maze,n,r,c+1);
        solMaze[r][c+1] = 0;
    }
    
    if(moveDown)
    {
        solMaze[r+1][c] = 1;
        moveRatInMaze(maze,n,r+1,c);
        solMaze[r+1][c] = 0;
    }
    
    return;
}
void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    memset(solMaze,0,(20*20*sizeof(int)));
    if(maze[0][0] != 1)
        return;
    solMaze[0][0] = 1;
    moveRatInMaze(maze,n,0,0);
}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
  
  return 0;
}

