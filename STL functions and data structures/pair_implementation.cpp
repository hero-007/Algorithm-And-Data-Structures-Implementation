#include<utility>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	
	// creating a pair 
	pair<int,string> p1(1,"Akhil");
	
	cout<<"Pair p1 -  first = "<<p1.first<<"  second = "<<p1.second<<endl;
	
	// using make_pair to create a pair
	pair<int,char> p2;
	
	p2 = make_pair(2,'A');
	cout<<"Pair p2 -  first = "<<p2.first<<"  second = "<<p2.second<<endl;
	
	// creating a vector of pairs
	vector< pair<int,string> > name(2);
	name[0].first = 1;
	name[0].second = "Akhil";
	
	name[1].first = 2;
	name[1].second = "George";
	
	for(int i=0;i<name.size();i++)
	{
		cout<<name[i].first<<" "<<name[i].second<<endl;
	}
	cout<<endl;
	return 0;
	
}
