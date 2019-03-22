#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v1(5);	// all 5 elements are intialized with 0
	
	// inserting elements into v1
	for(int i=0;i<v1.size();i++)
	{
		v1[i] = i+1;
	}
	
	// traversing the vector using iterator
	vector<int>::iterator it1;
	for(it1 = v1.begin();it1!=v1.end();it1++)
	{
		cout<<*it1<<" ";
	}
	cout<<endl;
	
	// creating a vector without size
	vector<int> v2;
	
	for(int i=6;i<=10;i++)
	{
		v2.push_back(i);
	}
	
	// traversing a vector without iterators
	for(int k=0;k<v2.size();k++)
	{
		cout<<v2[k]<<" ";
	}
	cout<<endl;
	
	// copying one vector to another 
	vector<int> v3 = v2;
	
	for(int i=0;i<v3.size();i++)
	{
		v3[i] = v3[i]+1;
		cout<<v3[i]<<" ";
	}
	cout<<endl;
	
	// creating a vector v4 and initialize all its elements with 5
	vector<int> v4(10,5);
	
	for(int i=0;i<v4.size();i++)
	{
		cout<<v4[i]<<" ";
	}
	cout<<endl;
	return 0;
	
}
