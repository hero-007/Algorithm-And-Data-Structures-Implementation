/**
Lazy propagation is used when you want to update in an interval [L,R] - Lazy propagation does it better than O(nlogn) i.e, Normal Segment tree


###################### MINIMUM SEGMENT TREE ##################################
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
	return;
}

int querySegmentTree(int *tree,int st,int ed,int treeNode,int left_limit,int right_limit)
{
	/**
	Total 3 cases are required to be handled -
	1 - complete overlap 
	2 - no overlap
	3 - partial overlap
	**/
	
	// complete overlap
	if(st >= left_limit && ed <= right_limit)
		return tree[treeNode];
		
	// No overlap
	if(st > right_limit || ed < left_limit)
		return INT_MAX;
		
	// Partial Overlap
	int mid = (st+ed)/2;
	
	int a = querySegmentTree(tree,st,mid,2*treeNode,left_limit,right_limit);
	int b = querySegmentTree(tree,mid+1,ed,2*treeNode+1,left_limit,right_limit);
	return min(a,b);
}

// Update segment tree within a range using - LAZY_PROPAGATION
void updateSegmentTree(int *tree,int *lazy,int st,int ed,int treeNode,int left_update_limit,int right_update_limit,int inc)
{
	if(ed < st)
		return;
		
	// Before using any value from the segment tree update that value using the lazy tree
	if(lazy[treeNode]!=0)
	{
		tree[treeNode] += lazy[treeNode];
		if(ed!=st)
		{
			lazy[2*treeNode] += lazy[treeNode];
			lazy[2*treeNode+1] += lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	
	// No overlap 
	if(st > right_update_limit || ed < left_update_limit)
		return;
		
		
	// Complete Overlap
	if(st >= left_update_limit && ed <= right_update_limit)
	{
		tree[treeNode] += inc;
		if(st != ed)
		{
			// update the values of the children of this node in the lazy propagation tree
			lazy[2*treeNode] += inc;
			lazy[2*treeNode+1] += inc;
		}
		return;
	}
	
	// Partial Overlap
	int mid = (st+ed)/2;
	updateSegmentTree(tree,lazy,st,mid,2*treeNode,left_update_limit,right_update_limit,inc);
	updateSegmentTree(tree,lazy,mid+1,ed,2*treeNode+1,left_update_limit,right_update_limit,inc);
	
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
	return;
}

int main()
{
	cout<<"Enter size of the array : ";
	int n;
	cin>>n;
	
	int *arr = new int[n];
	int *lazy = new int[3*n];
	int *tree = new int[3*n];
	
	cout<<"Enter the elements of the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	memset(lazy,0,sizeof(int)*3*n);
	buildSegmentTree(arr,tree,0,n-1,1);
	
	cout<<"Enter the number of queries : ";
	int q;
	cin>>q;
	
	while(q--)
	{
		int ch,a,b,inc;
		
		// Two types of queries are -
		// 1 - update - 1 , a, b, inc
		// 2 - query - 2 , a, b
		
		cout<<"Enter choice : ";
		cin>>ch;
		
		if(ch == 1){
			cout<<"Enter a, b and inc : ";
			cin>>a>>b;
			cin>>inc;
		}
		else
		{
			cout<<"Enter a, b : ";
			cin>>a>>b;
		}
			
			
		if(ch == 1)
		{
			updateSegmentTree(tree,lazy,0,n-1,1,a-1,b-1,inc);
		}
		else
		{
			int result = querySegmentTree(tree,0,n-1,1,a-1,b-1);
			cout<<result<<endl;
		}
	}
	
	return 0;
}
