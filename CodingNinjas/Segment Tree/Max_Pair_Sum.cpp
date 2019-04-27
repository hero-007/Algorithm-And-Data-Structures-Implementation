/**
Maximum Pair Sum

You are given a sequence A[1], A[2], ..., A[N], ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). There are two types of operations and they are defined as follows:

Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 = i = N, and x, 0 = x = 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 = x < y = N.
You must find i and j such that x = i, j = y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q = 10^5, representing the number of operations. Next Q lines contain the operations.

Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12

**/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val_1;
    int val_2;
};

void buildSegmentTree(int *arr,Node *tree,int st,int ed,int treeNode)
{
    if(st == ed)
    {
        tree[treeNode].val_1 = arr[st];
        tree[treeNode].val_2 = INT_MIN;
        return;
    }
    
    int mid = (st+ed)/2;
    
    buildSegmentTree(arr,tree,st,mid,2*treeNode);
    buildSegmentTree(arr,tree,mid+1,ed,2*treeNode+1);
    
    
    Node left = tree[2*treeNode];
    Node right = tree[2*treeNode+1];
    
    
    tree[treeNode].val_1 = max(left.val_1,right.val_1);
    tree[treeNode].val_2 = min(max(left.val_1,right.val_2),max(left.val_2,right.val_1));
}

void updateTree(int *arr,Node *tree,int st,int ed,int treeNode,int idx,int val)
{
    if(st == ed)
    {
        arr[idx] = val;
        tree[treeNode].val_1 = val;
        tree[treeNode].val_2 = INT_MIN;
        return;
    }
    
    int mid = (st+ed)/2;
    
    if(idx <= mid)
        updateTree(arr,tree,st,mid,2*treeNode,idx,val);
    else
        updateTree(arr,tree,mid+1,ed,2*treeNode+1,idx,val);
    
    Node left = tree[2*treeNode];
    Node right = tree[2*treeNode+1];
    
    
    tree[treeNode].val_1 = max(left.val_1,right.val_1);
    tree[treeNode].val_2 = min(max(left.val_1,right.val_2),max(left.val_2,right.val_1));
}

Node getMinTree(Node *tree,int st,int ed,int treeNode,int left_limit,int right_limit)
{
    if(st >= left_limit && ed <= right_limit)
        return tree[treeNode];
    
    if(left_limit > ed || right_limit < st)
    {
        Node temp;
        temp.val_1 = INT_MIN;
        temp.val_2 = INT_MIN;
        return temp;
    }
    
    
    int mid = (st+ed)/2;
    
    Node left = getMinTree(tree,st,mid,2*treeNode,left_limit,right_limit);
    Node right = getMinTree(tree,mid+1,ed,2*treeNode+1,left_limit,right_limit);
    
    
    int max1 = max(left.val_1,right.val_1);
    int max2 = min(max(left.val_1,right.val_2),max(left.val_2,right.val_1));
    
    Node temp;
    temp.val_1 = max1;
    temp.val_2 = max2;
    return temp;
}

int main() {
    int n,q;
    cin>>n;
	
    int *arr = new int[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cin>>q;
    Node *tree = new Node[3*n];
    
    buildSegmentTree(arr,tree,0,n-1,1);
    
    
    while(q--)
    {
        char ch;
        int a,b;
        
        cin>>ch;
        cin>>a>>b;
        
        if(ch == 'Q')
        {
            Node result = getMinTree(tree,0,n-1,1,a-1,b-1);
            int res = (result.val_1 + result.val_2);
            cout<<res<<endl;
        }
        
        if(ch == 'U')
        {
            updateTree(arr,tree,0,n-1,1,a-1,b);
        }
    }
    
    return 0;
}

