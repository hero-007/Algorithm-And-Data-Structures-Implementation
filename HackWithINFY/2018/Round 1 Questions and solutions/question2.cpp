#include<bits/stdc++.h>
using namespace std;

int getNum(string s)
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

void getResult(string s)
{
	int lt = s.length();
	int ftr = 0;
	int ltr = 0;
	vector<int> arr;
	
	
	while(ltr < lt)
	{
		char ch = s[ltr];
		if(ch == ' ')
		{
			int k = ltr - ftr;
			string st = s.substr(ftr,k);
			int num = getNum(st);
			arr.push_back(num);
			ftr = ltr+1;
			
			if(ftr == lt)
				break;
		}
		ltr++;
	}
	
	
	int profit = 0;
	int avgProfit = 0;
	int l = arr.size();
	
	
	for(int i=0;i<l;i++)
	{
		int cp = arr[i];
		
		for(int j=i+1;j<l;j++)
		{
			int sp = arr[j];
			
			if(sp < cp)
				continue;
				
			int duration = j - i;
			int temp_profit = sp - cp;
			int temp_avgProfit = (sp - cp)/duration;
			
			if(temp_avgProfit > avgProfit)
			{
				profit = temp_profit;
				avgProfit = temp_avgProfit;
			}
			else
			{
				if(temp_avgProfit == avgProfit && temp_profit > profit)
				{
					profit = temp_profit;
					avgProfit = temp_avgProfit;
				}
			}
		}
	}
	
	if(profit != 0)
	{
		cout<<avgProfit<<" "<<profit<<endl;
	}
	else
	{
		cout<<"impossible"<<endl;
	}
}

int main()
{
	string s;
	getline(cin,s);
	
	s = s + ' ';
	getResult(s);
	
	return 0;
}

