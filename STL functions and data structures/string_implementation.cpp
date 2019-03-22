#include<iostream>
#include<string>

using namespace std;

int countWords(string s)
{
	int wordCount = 0;
	int pre = 0;
	string sub;
	
	for(int i=0;i<s.length();i++)
	{
		char ch = s[i];
		if(ch == ' ')
		{
			wordCount++;
			int k = i-pre;
			sub = s.substr(pre,k);
			pre = i+1;
			
			cout<<sub<<endl;
		}
	}
	
	return wordCount+1;
}

int main()
{
	// Intitalizing and copying strings
	string s1 = "Akhil";
	cout<<s1<<endl;
	
	string s2 = s1;
	cout<<s2<<endl;
	
	string s3(s1);
	cout<<s3<<endl;
	
	string s4(s1,0,3); // start index = 0 |||||| next = 3 characters including 0 ||||||| output = Akh
	cout<<s4<<endl;
	
	// Getting the size of the string 
	int l1 = s1.length();
	int l2 = s1.size();
	
	cout<<"Length of s1 = "<<l1<<endl;
	cout<<"Size of s1 = "<<l2<<endl;
	
	// concatinating 2 strings 
	string s5 = s1 + " Tiwari";
	cout<<s5<<endl;
	
	// comparing the contents of 2 strings 
	
	int a = s1.compare(s2);
	if ( a == 0)
	{
		cout<< s1 <<" = "<<s2<<endl;
	}
	else{
		cout<< s1 <<" not equal "<<s2<<endl;
	}
	
	// substring of a string 
	string s6 = s5; // s6 = Akhil Tiwari
	
	string s7 = s6.substr(0,4); // starting from 0 and next 4 characters - Akhi
	cout<<s7<<endl;
	
	// printing the content of the string character by character
	for(int i=0;s6[i]!='\0';i++)
	{
		char ch = s6[i];
		cout<<ch<<" ";
	}
	cout<<endl;
	
	
	// counting and printing the words in a string 
	string sample = "Hey guys my name is Akhil Tiwari";
	int wordCount = countWords(sample);
	cout<<"Number of words in - "<<sample<<" = "<<wordCount<<endl;
	
	return 0;
}
