#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public:
		trieNode * left;
		trieNode * right;
		
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
			// current node of the value is 0
			if(!curr->left)
			{
				// left of the current node does not exist so create a new node at left
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else
		{
			// current node of the value is 1
			if(!curr->right)
			{
				// right of the current node does not exist so create a new right 
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int getMaxXorPossible(trieNode *head,int *arr,int n)
{
	int max_xor = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int value = arr[i];
		int current_xor = 0;
		trieNode * curr = head;
		
		for(int j=31;j>=0;j--)
		{
			int b = (value>>j)&1;
			
			if(b != 0)
			{
				// current bit is 1
				// go to left if possible
				if(curr->left)
				{
					curr = curr->left;
					current_xor += pow(2,j);
				}
				else
				{
					curr = curr->right;
				}
			}
			else
			{
				// current bit is 0
				// goto right if possible
				if(curr->right)
				{
					curr = curr->right;
					current_xor += pow(2,j);
				}
				else
				{
					curr = curr->left;
				}
			}
		}
		
		if(current_xor > max_xor)
			max_xor = current_xor;
	}
	
	return max_xor;
}


int main()
{
	int arr[5] = {1,5,3,10,7};
	trieNode *head = new trieNode();
	
	for(int j=0;j<5;j++)
		insert(arr[j],head);
		
	int result = getMaxXorPossible(head,arr,5);
	cout<<result<<endl;
	
	return 0;
}
