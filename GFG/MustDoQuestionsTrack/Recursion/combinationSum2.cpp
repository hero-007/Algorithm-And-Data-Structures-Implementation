#include<bits/stdc++.h>
using namespace std;

void givePairCount(int *arr,int sum,int n,int pos,vector<int> mystack,int &status)
{
	if(sum == 0)
	{
		// print the stack
		cout<<"(";
		int l = mystack.size();
		for(int i=0;i<l;i++)
		{
		    cout<<mystack[i];
		    if(i != l-1)
		        cout<<" ";
		}
		cout<<")";
		
		status = 1;
		
	}
	
	if(pos == n)
		return;
		
	unordered_set<int> keep;
	
	for(int i=pos;i<n;i++)
	{
		int t= arr[i];
		if(t <= sum && keep.find(t) == keep.end())
		{
			mystack.push_back(t);
			keep.insert(t);
			givePairCount(arr,sum-t,n,i+1,mystack,status);
			mystack.pop_back();
		}
	}
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	int n;
	cin>>n;
	
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int sum;
	cin>>sum;
	int status = -1;
	
	sort(arr,arr+n);
	vector<int> cont;
	
	givePairCount(arr,sum,n,0,cont,status);
	
	if(status == -1)
        cout<<"Empty"<<endl;
    else 
        cout<<endl;
    }
	return 0;
}
