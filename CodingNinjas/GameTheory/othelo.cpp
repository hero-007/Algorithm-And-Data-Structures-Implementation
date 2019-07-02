#include<bits/stdc++.h>
using namespace std;

int board[8][8];

bool isMovePossible(int player,int x,int y,int stepX,int stepY)
{
	if(x<0 || x>=8 || y<0 || y>=8)
		return false;
		
	if(board[x][y] == player)
	{
		
	}
	
	bool checkYa = isMovePossible(player,x+stepX,y+stepY,stepX,stepY);
	return checkYa;
}

bool move(int player,int x,int y)
{
	// This function has three jobs to do 
	// check if (x,y) is a valid position to move
	// make move if (x,y) is a valid position and make all converstions
	
	int x_moves[] = {-1,-1,0,+1,+1,+1,0,-1};
	int y_moves[] = {0,+1,+1,+1,0,-1,-1,-1};
	
	bool status = false;
	for(int i=0;i<8;i++)
	{
		bool move_possible = isMovePossible(player,x,y,x_moves[i],y_moves[i]);
		if(move_possible)
		{
			status = true;
			makeMove(player,x,y,x_moves[i],y_moves[i]);
		}
	}
	
	if(status == false)
		return false;
	return true;
	
}
