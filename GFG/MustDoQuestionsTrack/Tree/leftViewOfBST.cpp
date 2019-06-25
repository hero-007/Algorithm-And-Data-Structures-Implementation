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

void leftView(treeNode *root)
{
    if(root == NULL)
        return;
    
    treeNode *temp = root;
    queue<treeNode*> q;
    
    temp->level = 0;
    q.push(temp);
    
    int max_level = -1;
    
    while(!q.empty())
    {
        treeNode* front = q.front();
        
        if(front->level > max_level)
        {
            cout<<front->val<<" ";
            max_level = front->level;
        }
        
        if(front->left!= NULL)
        {
            q.push(front->left);
            front->left->level = front->level + 1;
        }
        
        if(front->right != NULL)
        {
            q.push(front->right);
            front->right->level = front->level + 1;
        }
        
        q.pop();
    }
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
	
	leftView(root);
	return 0;
	
}
