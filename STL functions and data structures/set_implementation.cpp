#include<iostream>
#include<set>
using namespace std;

/* Set is implemented using balanced BST in c++. So operations like insert, find takes O(log n) time. */


int main()
{
	int arr[] = {1,2,23,1,2,23,5,6,2,6};
	int n = sizeof(arr)/sizeof(int);
	
	set<int> s;
	
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	
	// printing the content of the set 
	set<int>::iterator it;
	cout<<"Contents of set - ";
	for(it = s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}	
	cout<<endl;
	
	// searching for an element in set
	set<int>::iterator it1 = s.find(23);
	cout<<*it1<<endl;
	
	if(it1 == s.end())
		cout<<"Element is not found"<<endl;
	else
		cout<<"Element found"<<endl;
	return 0;
}
