// working but inefficient
#include<bits/stdc++.h>
using namespace std;

struct treeNode{
	treeNode *left;
	int val;
	treeNode *right;
	int level;
	
	treeNode(int v)
	{
		left = NULL;
		val = v;
		right = NULL;
		level = -1;
	}
};

// MAIN CODE --------------------------------------------------
int giveMax(Node* root)
{
    if(root == NULL)
        return INT_MIN;
    
    int leftMax = giveMax(root->left);
    int rightMax = giveMax(root->right);
    
    return max(root->data,max(leftMax,rightMax));
}

int giveMin(Node* root)
{
    if(root == NULL)
        return INT_MAX;
    
    int leftMin = giveMin(root->left);
    int rightMin = giveMin(root->right);
    
    return min(root->data,min(leftMin,rightMin));
}

bool isBST(Node* root)
{
    if(root == NULL)
        return true;
        
    bool isleftBst = isBST(root->left);
    bool isrightBst = isBST(root->right);
    
    if(!isleftBst || !isrightBst)
        return false;
    
    int leftMax = giveMax(root->left);
    int rightMin = giveMin(root->right);
    
    if(root->data > leftMax && root->data < rightMin)
        return true;
    else 
        return false;
}

// MAIN CODE -------------------------------------------
treeNode* insertBST(treeNode *root,int value)
{
	if(root == NULL)
	{
		treeNode *n = new treeNode(value);
		return n;
	}
	
	if(value > root->val)
		root->right = insertBST(root->right,value);
	else
		root->left = insertBST(root->left,value);
		
	return root;
}

int main()
{
	int n;
	cin>>n;
	
	treeNode *root = NULL;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		root = insertBST(root,a);
	}
	
	if(checkBST(root))
		cout<<"This tree is a bst";
	else
		cout<<"Not a bst";
		
	return 0;	
}
