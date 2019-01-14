#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int n; // storing the number of rounds
	
	cin>>n;
		
	int s[n],t[n];
	int max_lead = 0,leader,diff = 0;
	
	cin >> s[0]>>t[0];	
	if (s[0]>t[0]){
		diff = s[0]-t[0];
		if (diff > max_lead){
			max_lead = diff;
			leader = 1;
		}
	}else{
		diff = t[0]-s[0];
		if (diff > max_lead){
			max_lead = diff;
			leader = 2;
		}
	}
	
	for(int i=1;i<n;i++){
		cin>>s[i]>>t[i];
		
		s[i] += s[i-1];
		t[i] += t[i-1];
		
		if (s[i] > t[i]){
			diff = s[i] - t[i];
			if (diff > max_lead)
			{
				max_lead = diff;
				leader = 1;
			}
		}
		else{
			diff = t[i] - s[i];
			if (diff > max_lead)
			{
				max_lead = diff;
				leader = 2;
			}
		}
		
	}
	
	cout<<leader<<" "<<max_lead;
	
	return 0;
}
