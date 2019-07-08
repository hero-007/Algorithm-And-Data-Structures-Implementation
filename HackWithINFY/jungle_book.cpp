#include<bits/stdc++.h>
using namespace std;

int minimumGroups(vector<int> predators)
{
	int max_len = 0;
	
	for(int i=0;i<predators.size();i++)
	{
		int count = 1;
		int eater = predators[i];
		
		while(eater != -1)
		{
			count++;
			eater = predators[eater];
		}
		
		if(count > max_len)
			max_len = count;
	}
	
	return max_len;
}

int main(){
    int n, key;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin>>a[i];
    }
    int group = minimumGroups(a);
    cout<<group<<endl;
}
