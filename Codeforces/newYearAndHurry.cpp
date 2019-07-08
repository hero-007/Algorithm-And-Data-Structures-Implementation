#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int time[10];
	time[0] = 5;
	
	for(int i=1;i<10;i++)
	{
		time[i] = (5 * (i+1)) + time[i-1];
	}
	
	int remaining = 240 - k;
	
	int prob = 0;
	int st = 0;
	int ed = n-1;
	
	while(st <= ed)
	{
		int mid = (st+ed)/2;
		
		if(time[mid] == remaining)
		{
			prob = mid+1;
			break;
		}
		
		else if(time[mid] < remaining)
		{
			prob = mid+1;
			st = mid+1;
		}
		
		else
		{
			ed = mid - 1;
		}
	}
	
	cout<<prob<<endl;
}
