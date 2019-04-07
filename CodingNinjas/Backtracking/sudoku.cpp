#include<bits/stdc++.h>
using namespace std;

int getBoxLimit(int a)
{
	if(a>=0 && a<=2)
		return 0;
	else if(a>=3 && a<=5)
		return 3;
	else 
		return 6;
}

bool isPossible(int board[9][9], int r,int c,int val)
{
	// This function will check whether it is possible to place the given number in this position or not
	
	// 1 - check in this row
	for(int i=0;i<9;i++)
	{
		if(board[r][i] == val)
			return false;
	}
	
	// 2 - check in this column
	for(int j=0;j<9;j++)
	{
		if(board[j][c] == val)
			return false;
	}
	
	// 3 - check in this box of 3 * 3
	int lr = getBoxLimit(r);
	int lc = getBoxLimit(c);
	for(int m=lr;m<=(lr+2);m++)
	{
		for(int n=lc;n<=(lc+2);n++)
		{
			if(board[m][n] == val)
				return false;
		}	
	}
	
	return true;
}

bool findEmptyPosition(int board[9][9],int &r,int &c)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j] == 0)
			{
				r = i;
				c = j;
				return true;
			}
		}
	}
	
	return false;
}

bool sudoku(int board[9][9])
{
	int r,c;
	bool status = findEmptyPosition(board,r,c);
	
	if(status == false)
	{
		return true;
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			bool ifPossible = isPossible(board,r,c,i);
			if(ifPossible)
			{
				board[r][c] = i;
				bool a = sudoku(board);
				if(a)
					return true;
			}
		}
		board[r][c] = 0;
		return false;
	}
}


int main()
{
	int board[9][9];
	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>board[i][j];
		
	bool a = sudoku(board);
	// print the result
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
