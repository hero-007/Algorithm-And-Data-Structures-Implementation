/**
SUBXOR

A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.

Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.

Output Format
For each test case, print the required answer.

Constraints:
1 = T = 5
1 = N = 10^5
1 = A[i] = 10^5
1 = K = 10^6

Sample Input
1
5 2
4 1 3 2 7   

Sample Output
3

**/
#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public:
		trieNode *left;
		trieNode *right;
		int Ldata;
		int Rdata;
		
		trieNode()
		{
			this->Ldata = 0;
			this->Rdata = 0;
			this->left = NULL;
			this->right = NULL;
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
			curr->Ldata++;
			if(!curr->left)
			{
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else
		{
			// goto right and if right does not exist then create it
			curr->Rdata++;
			if(!curr->right)
			{
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}


int subarrayXorLessThanK(trieNode *currhead,int k,int element)
{
	int countSub = 0;
	
	if(currhead == NULL)
		return 0;
	
	
	trieNode *head = currhead;
		
		for(int j=31;j>=0;j--)
		{
			int p = (element>>j)&1;
			int t = (k>>j)&1;
			
			
			if(p == 1 && t == 1 )
			{
				countSub += (head->Rdata);
				if(head->left == NULL) return countSub;
				head = head->left;
			}
			else if(p == 1 && t == 0 )
			{
				if(head->right == NULL) return countSub;
				head = head->right;
			}
			else if(t == 1 && p == 0 )
			{
				countSub += (head->Ldata);
				if(head->right == NULL)return countSub;
				head = head->right;
			}
			else if(t == 0 && p == 0)
			{
				if(head->left == NULL)return countSub;
				head = head->left;
			}			
		}
		
	
	return countSub;
}

int main()
{
	int t;
    cin >>t;
    while(t--){
          int n;
          cin >> n; 
        int k;
        cin >>k;
        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++) cin >>arr[i];
        trieNode* root = new trieNode();
        insert(0 , root);
        
         long long count = 0;
           int p = 0;
           int value = 0;
            int x = 0;
        for(int j = 0 ; j < n ; j++){
              value = x^arr[j];
           count += (long long)subarrayXorLessThanK(root , k ,value);
                   insert(value , root);
                    x = value;
        }
        cout<<count<<endl;
    }
    return 0;
}
