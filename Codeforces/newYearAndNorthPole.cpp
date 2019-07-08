#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,string> >dir;
	for(int i=0;i<n;i++)
	{
		int a;
		string d;
		cin>>a;
		cin>>d;
		
		dir.push_back(make_pair(a,d));
	}
	
	bool status = true;
	
	if(dir[0].second != "South" || dir[n-1].second != "North")
		cout<<"NO"<<endl;
	else
	{
		int vertical_dist = 0;
		
		for(int i=0;i<n;i++)
		{
			int dist = dir[i].first;
			string d = dir[i].second;
			
			if(vertical_dist == 0 || vertical_dist == 20000)
			{
				if(d == "East" || d == "West")
				{
					status = false;
					break;
				}
			}
			
			if(d == "East" || d == "West")
				continue;
			
			if(d == "South")
			{
				vertical_dist += dist;
				if(vertical_dist > 20000)
				{
					status = false;
					break;
				}
			}
			
			if(d == "North")
			{
				vertical_dist -= dist;
				if(vertical_dist < 0)
				{
					status = false;
					break;
				}
			}
		}
		
		if(status == true && vertical_dist == 0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
