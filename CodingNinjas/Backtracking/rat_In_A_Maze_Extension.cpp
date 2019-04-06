#include<bits/stdc++.h>
using namespace std;

void printSolMaze(int **solMaze,int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<solMaze[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void moveRatInMaze(int maze[][20],int **solMaze,int n,int r,int c)
{
	if(r == n-1 && c == n-1)
	{
		solMaze[r][c] = 1;
		printSolMaze(solMaze,n);
		solMaze[r][c] = 0;
		return;
	}
	
	if(r == n || r == -1 || c == n || c == -1 || maze[r][c] == 0 || solMaze[r][c] == 1)
		return;
	else
	{
		solMaze[r][c] = 1;
		moveRatInMaze(maze,solMaze,n,r-1,c);
		moveRatInMaze(maze,solMaze,n,r+1,c);
		moveRatInMaze(maze,solMaze,n,r,c-1);
		moveRatInMaze(maze,solMaze,n,r,c+1);
		solMaze[r][c] = 0;
		return;
	}
}
void ratInAMaze(int maze[][20],int n)
{
	int **solMaze = new int* [20];
	for(int i=0;i<20;i++)
	{
		solMaze[i] = new int[20];
		for(int j=0;j<20;j++){
			solMaze[i][j] = 0;
		}
	}
	
	moveRatInMaze(maze,solMaze,n,0,0);
	return;
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

