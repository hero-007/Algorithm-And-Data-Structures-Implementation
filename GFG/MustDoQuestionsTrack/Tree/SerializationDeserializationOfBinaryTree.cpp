void serialize(Node *root,vector<int> &A)
{
    // for serialization use pre-order traversal
    if(root == NULL)
    {
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}
/*this function deserializes
 the serialized vector A*/
Node* deserializeArray(vector<int> &A,int &index)
{
    if(index > A.size() || A[index] == -1)
    {
        index+=1;
        return NULL;
    }
    
    Node* root = new Node;
    root->data = A[index];
    index+=1;
    
    root->left = deserializeArray(A,index);
    root->right = deserializeArray(A,index);
    
    return root;
}

Node * deSerialize(vector<int> &A)
{
   int index = 0;
   Node* root = deserializeArray(A,index);
   return root;
}
