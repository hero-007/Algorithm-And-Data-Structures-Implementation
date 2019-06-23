/** Bolier Plate code for working with unspecified length of input integers **/

#include<bits/stdc++.h>
using namespace std;


int cnv2Num(string s)
{
	int l = s.length();
	int num = 0;
	
	for(int i=0;i<l;i++)
	{
		int letter = (int)s[i] - 48;
		num = (num * 10) + letter;
	}
	
	return num;
}

vector<int>* getNumbers(string s)
{
	vector<int> *numbers = new vector<int>;
	
	stringstream ss(s);
	while(ss)
	{
		string word;
		ss>>word;
		
		int num = cnv2Num(word);
		numbers->push_back(num);
	}
	
	// removes 0 at the last index of the vector 
	numbers->pop_back();
	
	return numbers;
}

int main()
{
	string st;
	getline(cin,st);
	
	vector<int> *numbers = getNumbers(st);
	
	/**
	
	code for printing the elements of the vector numbers
	
	vector<int>::iterator it = numbers->begin();
	while(it!=numbers->end())
	{
		cout<<*it<<endl;
		it++;
	}
	cout<<numbers->size()<<endl;
	
	**/
	
	
	return 0;
}
