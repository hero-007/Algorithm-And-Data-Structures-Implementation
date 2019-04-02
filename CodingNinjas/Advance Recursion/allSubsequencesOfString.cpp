#include<iostream>
#include<cmath>
using namespace std;

int generate_Subseq(string s,string output[])
{
	if(s.empty())
	{
		output[0]="";
		return 1;
	}
	string smallString = s.substr(1);
	int smallSize = generate_Subseq(smallString,output);
	for(int i=0;i<smallSize;i++)
	{
		output[smallSize + i] = s[0]+output[i];
	}
	
	return 2*smallSize;
}

int main()
{
	string s;
	cout<<"Enter the string : ";
	cin>>s;
	cout<<"All possible subsequence are :\n";
	int l = s.size();
	int output_size = pow(2,l);
	string *output = new string[output_size];
	
	int k = generate_Subseq(s,output);
	for(int j=0;j<k;j++)
		cout<<output[j]<<endl;
	cout<<endl;
	delete []output;
}
