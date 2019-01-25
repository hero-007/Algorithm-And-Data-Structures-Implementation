/** Question - Find the length of the connected cells of 1s (regions) in an matrixs of 1s and 0s **/

#include<iostream>

using namespace std;

int getVal(int a[][],int i,int j,int H,int L)
{
	if (i<0 || i>=H || j<0 || j>=L)
		return 0;
	else
		return a[i][j];
}

void findMaxOnes(int a[][],int i,int j,int H,int L,int size,int *max_size,bool cntr[][])
{
	if (i>H || j>L)
		return;
	size++;
	cntr[i][j] = true;
	
	if (max_size < size)
		max_size = size;
	
	int directions[][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	for (int i=0;i<8;i++){
		int new_i = i + directions[i][0];
		int new_j = j + directions[j][0];
		
		int new_v = getVal(a,new_i,new_j,H,L);
		if (new_v > 0 && cntr[new_i][new_j] == false)
			return findMaxOnes(a,new_i,new_j,H,L,size,max_size,cntr);
			
	}
	cntr[i][j] = false;
}

void getMaxOnes(int a[][],int max_rows,int max_cols)
{
	int max_size = 0;
	int size = 0;
	bool cntr[max_rows][max_cols] ={false};
	for (int i=0;i<max_rows;i++)
	{
		for (int j=0;j<max_cols;j++)
		{
			findMaxOnes(a,i,j,max_rows,max_cols,size,&max_size,cntr);
		}
	}
	
	return max_size; 
}

int main()
{
	int row,column;
	cout<<"Enter the value of row = ";
	cin>>row;
	cout<<"Enter the value of column = ";
	cin>>column;
	
	int arr[row][column];
	
	printf("Enter the elements of the array below : \n");
	for (int i=0;i<row;i++)
		for (int j=0;j<column;j++)
			scanf("%d",arr[i][j]);
			
	int max_size = getMaxOnes(arr,row,column);
	printf("\nMaximum region of one's in this matrix = %d\n",max_size);
	return 0;
}
