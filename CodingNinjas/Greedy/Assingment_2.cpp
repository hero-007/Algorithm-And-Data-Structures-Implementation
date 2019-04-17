/**
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help

Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array

Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array

1 =< N <= 10^5 
1 <= Ai,K <= 10^9

Sample Input - 
3 6
1 15 10

Sample Output- 
5

**/
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    int initial = arr[n-1] - arr[0];
    int small = arr[0]+k;
    int big = arr[n-1]-k;
    
    if(small > big)
    {
        int temp = small;
        small = big;
        big = temp;
    }
    
    for(int i=1;i<=n-2;i++)
    {
        int addr = arr[i] + k;
        int subtr = arr[i] - k;
        
        if(addr <= big || subtr >= small)
            continue;
        else
        {
            if(addr-small <= big-subtr)
            {
                big = addr;
            }
            else
            {
                small = subtr;
            }
        }
    }
    if(big-small < initial)
        cout<<big-small<<endl;
    else
        cout<<initial<<endl;
    
}
