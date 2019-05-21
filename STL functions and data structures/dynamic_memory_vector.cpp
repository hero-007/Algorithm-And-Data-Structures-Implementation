#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	vector<int> * arr = new vector<int>();
	arr->push_back(10);
	arr->push_back(20);
	
	
	vector<int> :: iterator it = arr->begin();
	while(it != arr->end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	delete arr;
	return 0;
}
