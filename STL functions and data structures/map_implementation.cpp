#include<iostream>
#include<map>
using namespace std;


void map_implementation()
{
	// Map is implemented using Balanced BST in C++
	// So operations like find() and erase() takes O(log n) time
	
	int arr[] = {1,2,1,1,1,2,3,34,23,23,32,43};
	int n = sizeof(arr)/sizeof(int);
	
	map<int,int> m1;
	
	for(int i=0;i<n;i++)
	{
		// counting the frequency of each number 
		m1[arr[i]] = m1[arr[i]] + 1;
	}
	
	// printing the contents of the map
	map<int,int>::iterator it;
	for(it = m1.begin();it!=m1.end();it++)
	{
		int first = it->first;
		int second = it->second;
		
		cout<<first<<" = "<<second<<endl;
	}
	
	map<int,int>::iterator it2= m1.find(1);
	if(it2 == m1.end())
	{
		cout<<"No such key was found"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<it2->first<<" = "<<it2->second<<endl;
	}
	
}

void unordered_map_implementation()
{
	// unordered_map is implelemented using hash table in C++
	// So operations like find() and erase() takes O(1) time in average case and O(n) time in worst case
	 
}

int main()
{
	map_implementation();
	return 0;
}
