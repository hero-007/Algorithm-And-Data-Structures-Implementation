void printBottomView(Node *root,unordered_map<Node*,int> &mp,unordered_map<int,int> &res)
{
    int min_limit = INT_MAX;
    int max_limit = INT_MIN;
    
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    
    
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        int wt = mp[f];
        res[wt] = f->data;
        
        if(f->left!=NULL)
        {
            mp[f->left] = wt-1;
            q.push(f->left);
            if(wt-1 < min_limit)
                min_limit = wt-1;
        }
        
        if(f->right!=NULL)
        {
            mp[f->right] = wt+1;
            q.push(f->right);
            if(wt+1 > max_limit)
                max_limit = wt+1;
        }
    }
    
    for(int i=min_limit;i<=max_limit;i++)
        cout<<res[i]<<" ";
}

void bottomView(Node *root)
{
   unordered_map<Node*,int> mp;
   unordered_map<int,int> res;
   mp[root] = 0;
   printBottomView(root,mp,res);
}

