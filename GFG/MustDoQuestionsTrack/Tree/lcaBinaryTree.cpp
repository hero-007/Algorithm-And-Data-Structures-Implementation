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


treeNode* lca(treeNode* root ,int n1 ,int n2 )
{
    if(root == NULL)
        return NULL;
        
    if(root->val == n1 || root->val == n2)
        return root;
    
    treeNode *left_tree = lca(root->left,n1,n2);
    treeNode *right_tree = lca(root->right,n1,n2);

    if(left_tree == NULL && right_tree == NULL)
        return NULL;
    else if(left_tree!=NULL && right_tree!=NULL)
        return root;
    else if(left_tree == NULL && right_tree!=NULL)
        return right_tree;
    else
        return left_tree;
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
	
	cout<<"Enter 2 nodes : ";
	int n1,n2;
	cin>>n1>>n2;
	
	treeNode *result = lca(root,n1,n2);
	cout<<"LCA : "<<result->val<<endl;
	return 0;
	
}
