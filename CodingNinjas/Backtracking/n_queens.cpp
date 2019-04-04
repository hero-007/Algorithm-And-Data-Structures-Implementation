#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int r,int c)
{
	// check whether any queen is present in the same column
	for(int i=r-1;i>=0;i--)
	{
		if(board[i][c] == 1)
			return false;
	}
	
	// check if any queen is present in the left diagonal 
	for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j] ==  1)
			return false;
	}
	
	// check if any queen is present in the right diagonal 
	for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
	{
		if(board[i][j] == 1)
			return false;
	}
	
	return true;
}

void placeQueens(int n,int r)
{
	if(r == n)
	{
		// all the queens have been placed successfully
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(isPossible(n,r,i))
		{
			board[r][i] = 1;
			placeQueens(n,r+1);
			board[r][i] = 0;
		}
	}
	
	return;
}

void queens(int n)
{
	memset(board,0,(11*11*sizeof(int)));
	placeQueens(n,0);
}

int main()
{
	cout<<"Enter the value of n : ";
	int n;
	cin>>n;
	
	queens(n);
	return 0;
}
