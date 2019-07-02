#include<bits/stdc++.h>
using namespace std;

string nimGame(vector<int> pile) {
    int nim_sum = pile[0];
    int n = pile.size();
    for(int i=1;i<n;i++)
    {
        nim_sum = nim_sum ^ pile[i];
    }

    if(nim_sum == 0)
        return "Second";
    return "First";
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> pile;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		pile.push_back(a);
	}
	
	string res = nimGame(pile);
	cout<<res<<endl;
	
	return 0;
}
