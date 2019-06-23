/** unspecified length of integers seprated by commas**/

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

vector<int>* giveNumbers(string st)
{
	vector<int> *numbers = new vector<int>;
	
	st = st+',';
	int l= st.length();
	
	int ftr = 0,ltr = 0;
	while(ltr < l)
	{
		if(st[ltr] == ',')
		{
			int k = ltr - ftr;
			string word = st.substr(ftr,k);
			
			int num = cnv2Num(word);
			numbers->push_back(num);
			
			ftr = ltr+1;
			if(ftr == l)
				break;
		}
		ltr++;
	}
	
	return numbers;
}

int main()
{
	string st;
	cin>>st;
	
	vector<int> *numbers = giveNumbers(st);
	
	// print the content of the vector
	int l = numbers->size();
	for(int i=0;i<l;i++)
		cout<<numbers->at(i)+1<<" ";
	cout<<endl;
	// print the content of the vector
	
	return 0;
}
