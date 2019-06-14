/**
Maximum XOR Subarray

Given an array of n integers, find subarray whose xor is maximum.

Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.

Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.

Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 

Sample Input
4
1 2 3 4
Sample Output
7

**/
#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public:
		trieNode *left;
		trieNode *right;
		
		trieNode()
		{
			left = NULL;
			right = NULL;
		}
};

void insert(int n,trieNode *head)
{
	trieNode *curr = head;
	for(int i=31;i>=0;i--)
	{
		int b = (n>>i)&1;
		
		if(b == 0)
		{
			// goto left and if left does not exist then create it
			if(!curr->left)
			{
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else
		{
			// goto right and if right does not exist then create it
			if(!curr->right)
			{
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxSubarrayXor(int *arr,int *xor_arr,int n,trieNode * head)
{
	int max_xor = INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		int curr_xor = xor_arr[i];
		int cx = 0;
		trieNode *temp_head = head;
		
		for(int j=31;j>=0;j--)
		{
			int b = (curr_xor>>j)&1;
			
			if(b!=0)
			{
				// current bit is 1
				// try to goto left if possible otherwise goto right
				if(temp_head->left)
				{
					// left exists
					cx += pow(2,j);
					temp_head = temp_head->left;
				}
				else
				{
					// left does not exist then goto right
					temp_head = temp_head->right;
				}
			}
			else
			{
				// current bit is 0
				// try to goto right if possible otherwise goto left
				if(temp_head->right)
				{
					// right exists
					cx += pow(2,j);
					temp_head = temp_head->right;
				}
				else
				{
					// right does not exist then goto left
					temp_head = temp_head->left;
				}
			}
		}
		
		int temp_max = curr_xor;
		if(cx > temp_max)
			temp_max = cx;
			
		// Now check for the global maximum
		if(temp_max > max_xor)
			max_xor = temp_max;
			
		insert(curr_xor,head);
	}
	
	return max_xor;
}

int main()
{
	int n;
	cin>>n;
	
	trieNode *head = new trieNode();
	
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr[i] = a;
	}
	
	int *xor_arr = new int[n];
	xor_arr[0] = arr[0];
	insert(arr[0],head);
	
	for(int j=1;j<n;j++)
	{
		xor_arr[j] = arr[j] ^ xor_arr[j-1];
	}
	
	
	int max_xor = findMaxSubarrayXor(arr,xor_arr,n,head);
	cout<<max_xor<<endl;
	
	return 0;
}
