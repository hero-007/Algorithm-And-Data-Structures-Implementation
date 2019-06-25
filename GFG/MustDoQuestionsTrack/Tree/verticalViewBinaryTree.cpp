void fillPriority(Node *root,unordered_map<Node*,int> &mp,int &max_priority,int &min_priority,unordered_map< int,vector<int> >&ptr)
{
    if(root == NULL)
        return;
        
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int wt = mp[f];
        
        ptr[wt].push_back(f->data);
        
        if(f->left!=NULL){
            q.push(f->left);
            mp[f->left] = wt-1;
            
            if(wt-1 < min_priority)
                min_priority = wt-1;
        }
        
        if(f->right!=NULL){
            q.push(f->right);
            mp[f->right] = wt+1;
            
            if(wt+1 > max_priority)
                max_priority = wt+1;
        }
    }
}


void verticalOrder(Node *root)
{
    int max_priority = INT_MIN;
    int min_priority = INT_MAX;
    unordered_map<Node*,int> mp;
    unordered_map< int,vector<int> >ptr;
    mp[root] = 0;
    
    fillPriority(root,mp,max_priority,min_priority,ptr);
    
    for(int i=min_priority;i<=max_priority;i++)
    {
        vector<int> temp = ptr[i];
        vector<int>::iterator it = temp.begin();
        while(it!=temp.end())
        {
            cout<<*it<<" ";
            it++;
        }
    }
}
