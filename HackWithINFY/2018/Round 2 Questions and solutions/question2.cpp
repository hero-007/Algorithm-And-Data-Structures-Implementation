#include<bits/stdc++.h>
using namespace std;

#define DAYS_IN_WEEK 7

int getCurrent(int *arr,int start)
{
	int res = arr[0]*20*20*18*20;
	res += arr[1]*20*18*20;
	res += arr[2]*18*20;
	res += arr[3]*20;
	res += arr[4];
	
	return res-start+1;
}

void showDate(int days)
{
	int years = days/365;
	
	int finl_year = 2000 + years;
	
	days = days - (365*years);
	
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	int monthCount = 0;
	while(days > 0)
	{
			if(days <= months[monthCount])
			{
				break;
			}
			
			days = days - months[monthCount];
			monthCount++;
	}
	
	int countLeap = years/4 + 1;
	days = days - countLeap;
	cout<<days<<":"<<monthCount+1<<":"<<finl_year<<endl;
}

int main()
{
	int arr[5] = {0};
	for(int i=0;i<5;i++)
	{
		int a;
		cin>>a;
		arr[i] = a;
		
		if(i!=4)
		{
			char ch;
			cin>>ch;
		}
	}
	
	
	int start = 2018843;
	int res = getCurrent(arr,start);
	cout<<res<<endl;
	
	showDate(res);
}
