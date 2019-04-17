#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	map<int,int> xy;
	int max_a = INT_MIN,max_b = INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		
		a = a/2;
		b = b/2;
		
		xy[a] = b;
		
		if(a > max_a)
			max_a = a;
		
		if(b > max_b)
			max_b = b;
	}
	
	int quarter_area = 0;
	int height[max_a] = {0};
	int prev_height = 0;
	
	for(int i=max_a;i>0;i--)
	{
		int current_height = xy[i];
		if(current_height < prev_height)
		{
			height[i-1] = prev_height;
		}
		else
		{
			prev_height = current_height;
			height[i-1] = current_height;
		}
	}
	
	for(int i=0;i<max_a;i++)
		quarter_area = quarter_area + height[i];
		
	cout<<"result : "<<quarter_area*4<<endl;
	
	return 0;
}
