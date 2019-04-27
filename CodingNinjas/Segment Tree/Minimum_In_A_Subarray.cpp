/**
Minimum In SubArray

Range Minimum Query

Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.

Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.

Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:
1=N,Q,y=10^5
1=l,r,x=N

Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output :
1
1
2
1

**/

#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *arr,int *tree,int st,int ed,int treeNode)
{
    if(st == ed)
    {
        tree[treeNode] = arr[st];
        return;
    }
    
    int mid = (st+ed)/2;
    
    buildSegmentTree(arr,tree,st,mid,2*treeNode);
    buildSegmentTree(arr,tree,mid+1,ed,2*treeNode+1);
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateTree(int *arr,int *tree,int st,int ed,int treeNode,int idx,int val)
{
    if(st == ed)
    {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    
    int mid = (st+ed)/2;
    
    if(idx <= mid)
        updateTree(arr,tree,st,mid,2*treeNode,idx,val);
    else
        updateTree(arr,tree,mid+1,ed,2*treeNode+1,idx,val);
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

int getMinTree(int *tree,int st,int ed,int treeNode,int left_limit,int right_limit)
{
    if(st >= left_limit && ed <= right_limit)
        return tree[treeNode];
    
    if(left_limit > ed || right_limit < st)
        return INT_MAX;
    
    int mid = (st+ed)/2;
    int ans1 = getMinTree(tree,st,mid,2*treeNode,left_limit,right_limit);
    int ans2 = getMinTree(tree,mid+1,ed,2*treeNode+1,left_limit,right_limit);
    
    return min(ans1,ans2);
}

int main() {
    int n,q;
    cin>>n>>q;
	
    int *arr = new int[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int *tree = new int[4*n];
    
    buildSegmentTree(arr,tree,0,n-1,1);
    
    
    while(q--)
    {
        char ch;
        int a,b;
        
        cin>>ch;
        cin>>a>>b;
        
        if(ch == 'q')
        {
            int result = getMinTree(tree,0,n-1,1,a-1,b-1);
            cout<<result<<endl;
        }
        
        if(ch == 'u')
        {
            updateTree(arr,tree,0,n-1,1,a-1,b);
        }
    }
    
    return 0;
}

