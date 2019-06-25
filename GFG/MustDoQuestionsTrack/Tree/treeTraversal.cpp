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

void inorder(treeNode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

void preorder(treeNode *root)
{
	if(root != NULL)
	{
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(treeNode *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}

void levelorder(treeNode *root)
{
	if(root == NULL)
		return;
	
	treeNode *temp = root;
	temp->level = 0;
	
	queue<treeNode *> level;
	level.push(temp);
	
	while(!level.empty())
	{
		treeNode* front = level.front();
		
		if(front->left != NULL){
			level.push(front->left);
			front->left->level = front->level + 1;
		}
		
		if(front->right != NULL){
			level.push(front->right);
			front->right->level = front->level + 1;
		}
		
		cout<<front->val<<" ";
		level.pop();
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
	cout<<"Inorder : ";
	inorder(root);
	cout<<endl;
	
	cout<<"Preorder : ";
	preorder(root);
	cout<<endl;
	
	cout<<"Postorder : ";
	postorder(root);
	cout<<endl;
	
	cout<<"Levelorder : ";
	levelorder(root);
	cout<<endl;
	
	return 0;
}

