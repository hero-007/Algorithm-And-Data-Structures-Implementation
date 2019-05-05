/**
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.

Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.

Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.

Constraints:
1= N,Q =10^6
1= Ai,Bi =10^9
1=Li=Ri

Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5

Sample Output
2
2
4
5
**/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int A;
    int B;
    int index;
};

Node getTheBest(Node left,Node right)
{
    Node temp;

    if(left.A != right.A)
    {
        if(left.A > right.A)
        {
            temp.A = left.A;
            temp.B = left.B;
            temp.index = left.index;
        }
        else
        {
            temp.A = right.A;
            temp.B = right.B;
            temp.index = right.index;
        }
    }
    else
    {
        if(left.B != right.B)
        {
            if(left.B < right.B)
            {
                temp.A = left.A;
                temp.B = left.B;
                temp.index = left.index;
            }
            else
            {
                temp.A = right.A;
                temp.B = right.B;
                temp.index = right.index;
            }
        }
        else
        {
            if(left.index < right.index)
            {
                temp.A = left.A;
                temp.B = left.B;
                temp.index = left.index;
            }
            else
            {
                temp.A = right.A;
                temp.B = right.B;
                temp.index = right.index;
            }
        }
    }
    
    return temp;
}

void buildTree(Node *arr,Node *tree,int st,int ed,int treeNode)
{
    if(st == ed)
    {
        tree[treeNode].A = arr[st].A;
        tree[treeNode].B = arr[st].B;
        tree[treeNode].index = arr[st].index;
        return;
    }
    
    int mid = (st+ed)/2;
    
    buildTree(arr,tree,st,mid,2*treeNode);
    buildTree(arr,tree,mid+1,ed,2*treeNode+1);
    
    Node left = tree[2*treeNode];
    Node right = tree[2*treeNode +1];
    
    tree[treeNode] = getTheBest(left,right);
    
}

Node getNodeIndex(Node *tree,int st,int ed,int treeNode,int left_limit,int right_limit)
{
    // Completely Within the range
    if(st >= left_limit && ed <= right_limit)
        return tree[treeNode];
    
    if(st > right_limit || ed < left_limit)
    {
        Node temp;
        temp.A = INT_MIN;
        temp.B = INT_MIN;
        temp.index = -1;
        return temp;
    }
    
    int mid = (st+ed)/2;
    
    Node left = getNodeIndex(tree,st,mid,2*treeNode,left_limit,right_limit);
    Node right = getNodeIndex(tree,mid+1,ed,2*treeNode+1,left_limit,right_limit);
    
    Node temp = getTheBest(left,right);
    return temp;
}

int main() {
    int n;
    cin>>n;
    
    Node *arr = new Node[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].A;
    }
    
    for(int j=0;j<n;j++)
    {
        cin>>arr[j].B;
        arr[j].index = j+1;
    }
    
    int q;
    cin>>q;
    Node *tree = new Node[3*n];
    
    buildTree(arr,tree,0,n-1,1);
    
    while(q--)
    {
        int left_limit,right_limit;
        cin>>left_limit>>right_limit;
        
        Node result = getNodeIndex(tree,0,n-1,1,left_limit-1,right_limit-1);
        cout<<result.index<<endl;
    }
}
