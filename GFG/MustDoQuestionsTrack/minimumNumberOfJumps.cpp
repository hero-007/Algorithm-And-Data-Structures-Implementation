#include <bits/stdc++.h>
using namespace std;

int minNumberSteps(int *arr,int n)
{
    if(n == 1)
        return 1;
    
    if(n == 0)
        return 0;
        
    int limit = 0;
    int steps = 0;
    int maxLimit = 0;
    
    for(int i=0;i<n-1;i++)
    {
        if(limit > n-1)
            break;
        
        int currentLimit = arr[i]+i;
        if(currentLimit > maxLimit)
            maxLimit = currentLimit;
            
        if(i==limit)
        {
            if(maxLimit > limit)
            {
                steps++;
                limit = maxLimit;
            }
            else
            {
                steps = -1;
                break;
            }
        }
    }
    return steps;
}
int main() {
    int t;	
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        int result = minNumberSteps(arr,n);
        cout<<result<<endl;
        
        delete []arr;
    }
    return 0;
}
