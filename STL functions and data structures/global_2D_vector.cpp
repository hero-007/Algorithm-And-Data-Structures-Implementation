#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > p(8,vector<int>(5,-1));

int main()
{
	int arr[5][7];
	memset(arr,-1,sizeof(arr));

	for(int i=0;i<p.size();i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
