#include<bits/stdc++.h>
using namespace std;

// Function - CreateSegmentTree() ------------- O(n)
void buildSegmentTree(int *arr,int *segmentTree,int start,int end,int treeNode) // it takes O(n) time to build the segment tree
{
	
	if(start == end)
	{
		segmentTree[treeNode] = arr[start];
		return;
	}
	
	int mid = (start+end)/2;
	
	buildSegmentTree(arr,segmentTree,start,mid,2*treeNode);
	buildSegmentTree(arr,segmentTree,mid+1,end,2*treeNode+1);
	
	segmentTree[treeNode] = segmentTree[2*treeNode] + segmentTree[2*treeNode+1];
}


// Funtion - UpdateSegmentTree() ------------------- O(log n)
void updateSegmentTree(int *arr,int *segmentTree,int start,int end,int treeNode,int idx,int val) // it takes O(log n) time to update the array and segmentTree
{
	if(start == end)
	{
		// we have reached the position where we must update
		segmentTree[treeNode] = val;
		arr[idx] = val;
		return;
	}
	
	int mid = (start+end)/2;
	
	if(idx > mid)
	{
		updateSegmentTree(arr,segmentTree,mid+1,end,2*treeNode+1,idx,val);
	}
	else
	{
		updateSegmentTree(arr,segmentTree,start,mid,2*treeNode,idx,val);
	}
	
	segmentTree[treeNode] = segmentTree[2*treeNode] + segmentTree[2*treeNode + 1];
	return;
	
}


// Function - QuerySegmentTree( [L,R] ) ------------------------- O(log n)
int querySegmentTree(int *segmentTree,int start,int end,int treeNode,int left_limit,int right_limit)
{
	/**
	There are there possible case and three possible actions for each case
	
	1 - interval is completely inside - return the value 
	2 - interval is completely outside - return a suitable value
	3 - interval is partially inside and partially outside - call the QuerySegmentTree on both the child nodes
	**/
	
	// when interval is completely inside
	if(start>=left_limit && end<=right_limit)
		return segmentTree[treeNode];
		
	// when interval is completely outside
	if(left_limit > end || right_limit < start)
		return 0;
		
	// when interval is partially inside and partially outside
	int mid = (start+end)/2;
	
	int ans1 = querySegmentTree(segmentTree,start,mid,2*treeNode,left_limit,right_limit);
	int ans2 = querySegmentTree(segmentTree,mid+1,end,2*treeNode+1,left_limit,right_limit);
	
	return (ans1+ans2);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	
	int n = sizeof(arr)/sizeof(int);
	
	int segmentTreeSize = 2*n;
	int *segmentTree = new int[segmentTreeSize];
	
	buildSegmentTree(arr,segmentTree,0,n-1,1);		// buildSegmentTree - O(n)
	
	
	updateSegmentTree(arr,segmentTree,0,n-1,1,3,99);  // change arr[3] = 99 and according to it update the segmentTree as well
	
	// Print all the elements of the segment tree
	for(int i=1;i<segmentTreeSize;i++)
		cout<<segmentTree[i]<<endl;
		
	int l,r;
	cout<<"Enter the limit to find its sum : ";
	cin>>l>>r;
	
	int result = querySegmentTree(segmentTree,0,n-1,1,l,r);
	cout<<"Answer is : "<<result<<endl;
	return 0;	
}
