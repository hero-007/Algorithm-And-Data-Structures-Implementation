/**
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-

Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9

Note:-

indexing starts from 1.

Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

Sample Output
2
2
4

**/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int even;
    int odd;
};

void buildTree(int *arr,Node *tree,int st,int ed,int treeNode)
{
     if(st == ed)
     {
         if(arr[st]%2 == 0)
         {
             tree[treeNode].even = 1;
             tree[treeNode].odd = 0;
         }
         else
         {
             tree[treeNode].even = 0;
             tree[treeNode].odd = 1;
         }
         return;
     }
    
    int mid = (st+ed)/2;
    
    buildTree(arr,tree,st,mid,2*treeNode);
    buildTree(arr,tree,mid+1,ed,2*treeNode+1);
    
    Node left = tree[2*treeNode];
    Node right = tree[2*treeNode+1];
    
    tree[treeNode].even = left.even + right.even;
    tree[treeNode].odd = left.odd + right.odd;
}

void updateTree(int *arr,Node *tree,int st,int ed,int treeNode,int idx,int val)
{
    if(st == ed)
    {
        if(val%2 == 0)
        {
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else
        {
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        arr[idx] = val;
        return;
    }
    
    int mid = (st+ed)/2;
    if(idx <= mid)
        updateTree(arr,tree,st,mid,2*treeNode,idx,val);
    else
        updateTree(arr,tree,mid+1,ed,2*treeNode+1,idx,val);
    
    Node left = tree[2*treeNode];
    Node right = tree[2*treeNode+1];
    
    tree[treeNode].even = left.even + right.even;
    tree[treeNode].odd = left.odd + right.odd;
}

Node queryTree(Node *tree,int st,int ed,int treeNode,int left_limit,int right_limit)
{
    if(st >= left_limit && ed <= right_limit)
        return tree[treeNode];
    
    if(st > right_limit || ed < left_limit)
    {
        Node temp;
        temp.even = 0;
        temp.odd = 0;
        return temp;
    }
    
    int mid = (st+ed)/2;
    Node left = queryTree(tree,st,mid,2*treeNode,left_limit,right_limit);
    Node right = queryTree(tree,mid+1,ed,2*treeNode+1,left_limit,right_limit);
    
    Node temp;
    temp.even = left.even + right.even;
    temp.odd = left.odd + right.odd;
    return temp;
}


int main() {

	int n;
    cin>>n;
    
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    Node *tree = new Node[3*n];
    
    int q;
    cin>>q;
    
    buildTree(arr,tree,0,n-1,1);
    
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        
        if(a == 0)
        {
            updateTree(arr,tree,0,n-1,1,b-1,c);
        }
        
        else 
        {
            Node result = queryTree(tree,0,n-1,1,b-1,c-1);
            
            if(a == 1)
                cout<<result.even<<endl;
            else
                cout<<result.odd<<endl;
        }
    }
    
    return 0;
}
