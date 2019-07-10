#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
void printMat(int M[MAX][MAX],int row,int col);
int main()
{
int T;
cin>>T;
while(T--)
{
	int n,m;
	cin>>n>>m;
	int a[MAX][MAX];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	printMat(a,n,m);
	cout<<endl;
}
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
class trieNode{
    public:
    trieNode *left,*right;
    string value;
    
    trieNode()
    {
        
        left = NULL;    // 0
        right = NULL;   // 1
        value = "";
    }
};

void insert(trieNode *head, int *arr,int n)
{
    trieNode *temp = head;
    for(int i=0;i<n;i++)
    {
        int a = arr[i];
        if(a == 1)
        {
            if(temp->right == NULL)
            {
                temp->right = new trieNode();
                temp->right->value = temp->value + "1 ";
                if(i == n-1)
                    cout<<temp->right->value<<"$";
            }
            temp = temp->right;
        }
        else
        {
            if(temp->left == NULL)
            {
                temp->left = new trieNode();
                temp->left->value = temp->value + "0 ";
                if(i == n-1)
                    cout<<temp->left->value<<"$";
            }
            temp = temp->left;
        }
    }
}

void printMat(int M[MAX][MAX],int row,int col)
{
    trieNode *head = new trieNode();
    
    for(int i=0;i<row;i++)
    {
        insert(head,M[i],col);
    }
    
}
