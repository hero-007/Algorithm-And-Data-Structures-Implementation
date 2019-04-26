#include<bits/stdc++.h>
using namespace std;

int getMinimumCost(int **input,int si,int sj,int ei,int ej,int **output) // output array is a 2-d DP array 
{
	if(si == ei && sj == ej){
		output[ei][ej] = input[ei][ej];
		return input[ei][ej];
	}
	
	if(si > ei || sj > ej)
		return INT_MAX;
		
	if(output[si][sj] > -1)
		return output[si][sj];
		
	int cost_1 = getMinimumCost(input,si,sj+1,ei,ej,output);
	int cost_2 = getMinimumCost(input,si+1,sj+1,ei,ej,output);
	int cost_3 = getMinimumCost(input,si+1,sj,ei,ej,output);
	
	int temp = input[si][sj] + min(cost_1,min(cost_2,cost_3));
	output[si][sj] = temp;
	return temp;
}

int main()
{
	int **input = new int *[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;
	
	int **output = new int *[3];
	output[0] = new int[3];
	output[1] = new int[3];
	output[2] = new int[3];
	output[0][0] = -1;
	output[0][1] = -1;
	output[0][2] = -1;
	output[1][0] = -1;
	output[1][1] = -1;
	output[1][2] = -1;
	output[2][0] = -1;
	output[2][1] = -1;
	output[2][2] = -1;
	
	int result = getMinimumCost(input,0,0,2,2,output);
	cout<<result<<endl;
	delete []input[0];
	delete []input[1];
	delete []input[2];
	delete []output[0];
	delete []output[1];
	delete []output[2];
	return 0;
}
