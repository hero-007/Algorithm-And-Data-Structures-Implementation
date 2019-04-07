#include<bits/stdc++.h>
using namespace std;

#define n 10 // size of the two dimensional character array

void printSoln(char arr[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
	cout<<endl;
}


bool isPossibleHorizontal(char arr[n][n],int r,int c,string word)
{
	for(int i=0;i<word.length();i++)
	{
		char ch = word[i];
		
		if(arr[r][c] == '-' || arr[r][c] == ch){
			c++;
			continue;
		}
		else
			return false;
	}
	
	return true;
}

bool isPossibleVertical(char arr[n][n],int r,int c,string word)
{
	for(int i=0;i<word.length();i++)
	{
		char ch = word[i];
		
		if(arr[r][c] == '-' || arr[r][c] == ch){
			r++;
			continue;
		}
		else
			return false;
	}
	
	return true;
}

void setWordHorizontal(char arr[n][n],string wrd,int r,int c,bool helper[])
{
	int lt = wrd.length();
	for(int i=c,j=0;j<lt;i++,j++)
	{
		if(arr[r][i] == '-'){
			arr[r][i] = wrd[j];
			helper[j] = true;
		}
		else
		{
			helper[j] = false;
		}
	}
}

void setWordVertical(char arr[n][n],string wrd,int r,int c,bool helper[])
{
	int lt = wrd.length();
	for(int i=r,j=0;j<lt;i++,j++)
	{
		if(arr[i][c] == '-'){
			arr[i][c] = wrd[j];
			helper[j] = true;
		}
		else
		{
			helper[j] = false;
		}
	}
}

void resetWordHorizontal(char arr[n][n],string wrd,int r,int c,bool helper[])
{
	int lt = wrd.length();
	for(int i=c,j=0;j<lt;i++,j++)
	{
		bool ct = helper[j];
		if(ct)
		{
			arr[r][i] = '-';
		}
	}
}

void resetWordVertical(char arr[n][n],string wrd,int r,int c,bool helper[])
{
	int lt = wrd.length();
	for(int i=r,j=0;j<lt;i++,j++)
	{
		bool ct = helper[j];
		if(ct)
		{
			arr[i][c] = '-';
		}
	}
}

int fillWords(string words[],string str)
{
	int lt = str.length();
	int temp_st = 0;
	int ct = 0;
	int index_i = 0;
	
	for(int j=0;j<lt;j++)
	{
		if(str[j] == ';' || j == lt-1)
		{
			if(j == lt-1)
				ct++;
				
			string stk = str.substr(temp_st,ct);
			temp_st = j+1;
			ct = 0;
			words[index_i] = stk;
			index_i++;
		}
		else
		{
			ct++;
		}
	}
	
	return index_i;
}

bool crossWord(string words[],char arr[n][n],int index,int size_words)
{
	if(index == size_words)
	{
		printSoln(arr);
		return true;
	}
	else
	{
		string wrd = words[index];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j] == '-' || arr[i][j] == wrd[0])
				{
					bool status = false;
					
					if(isPossibleHorizontal(arr,i,j,wrd))
					{
						int lt = wrd.length();
						bool helper[lt];
						setWordHorizontal(arr,wrd,i,j,helper);
						status = crossWord(words,arr,index+1,size_words);
						
						if(status)
							return true;
						else
						{
							resetWordHorizontal(arr,wrd,i,j,helper);
						}
					}
					
					if(isPossibleVertical(arr,i,j,wrd) && status == false)
					{
						int lt = wrd.length();
						bool helper[lt];
						setWordVertical(arr,wrd,i,j,helper);
						status = crossWord(words,arr,index+1,size_words);
						
						if(status)
							return true;
						else
						{
							resetWordVertical(arr,wrd,i,j,helper);
						}
					}
				}
			}
		}
		
		return false;
	}
}


int main()
{
	char arr[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
			
	string str;
	cin>>str;
	
	string words[100];
	int l = fillWords(words,str);
	
	crossWord(words,arr,0,l);
	
	return 0;
}

