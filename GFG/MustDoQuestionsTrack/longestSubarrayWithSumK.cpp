// longest subarray with sum equal to k
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    unordered_map<int,int> mp;
	    
	    int temp_sum = 0;
	    int max_len = 0;
	    
	    for(int i=0;i<n;i++)
	    {
	        temp_sum += arr[i];
	        
	        if(temp_sum == k)
	        {
	            max_len = i+1;
	        }
	        
	        if(mp.find(temp_sum) == mp.end())
	        {
	            mp[temp_sum] = i;
	        }
	        
	        int f = temp_sum - k;
	        if(mp.find(f) != mp.end())
	        {
	            if((i-mp[f]) > max_len)
	                max_len = i-mp[f];
	        }
	    }
	    
	    cout<<max_len<<endl;
	}
	return 0;
}
