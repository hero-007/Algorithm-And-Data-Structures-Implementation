bool checkBST(Node* root,int maxLimit,int minLimit)
{
    if(root == NULL)
        return true;
    
    if(root->data > maxLimit || root->data < minLimit)
        return false;
        
    bool leftTree = checkBST(root->left,root->data - 1,minLimit);
    bool rightTree = checkBST(root->right,maxLimit,root->data - 1);
    
    return (leftTree && rightTree);
}

bool isBST(Node* root) {
    bool status = checkBST(root,INT_MAX,INT_MIN);
    return status;
}

