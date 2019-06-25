#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node *left;
	int val;
	Node *right;
	int level;
	
	Node(int v)
	{
		left = NULL;
		val = v;
		right = NULL;
		level = -1;
	}
};

Node* insertBST(Node *root,int value)
{
	if(root == NULL)
	{
		Node *n = new Node(value);
		return n;
	}
	
	if(value > root->val)
		root->right = insertBST(root->right,value);
	else
		root->left = insertBST(root->left,value);
		
	return root;
}


void zigzag(Node *root)
{
    if(root == NULL)
        return;
        
    Node *temp = root;
    temp->level = 0;
    
    stack<int> reverse;
    queue<Node*> q;
    q.push(temp);
    int min_level = -1;
    
    while(!q.empty())
    {
        Node *f = q.front();
        if(f->level > min_level)
        {
            min_level = f->level;
            while(!reverse.empty())
            {
                cout<<reverse.top()<<" ";
                reverse.pop();
            }
        }
        
        if(f->left!=NULL)
        {
            q.push(f->left);
            f->left->level = f->level + 1;
        }
        
        if(f->right!=NULL)
        {
            q.push(f->right);
           f->right->level = f->level + 1;
        }
        
        if((f->level)%2 == 0)
            reverse.push(f->val);
        else
            cout<<f->val<<" ";
            
        q.pop();
    }
    
    while(!reverse.empty())
    {
        cout<<reverse.top()<<" ";
        reverse.pop();
    }
}

int main()
{
	int n;
	cin>>n;
	
	Node *root = NULL;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		root = insertBST(root,a);
	}
	
	zigzag(root);
	return 0;
}
