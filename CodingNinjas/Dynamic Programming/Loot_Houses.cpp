/**
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house

Output Format
 Line 1 : Maximum amount of money looted

Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4

Sample Input :
6
5 5 10 100 10 5

Sample Output 1 :
110
**/
#include<bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){

    int *loot = new int[n];
    loot[0] = arr[0];
    int result = loot[0];
    
    for(int i=1;i<n;i++)
    {
        int temp = 0;
        for(int j=i-2;j>=0;j--)
        {
            if(loot[j] > temp)
                temp = loot[j];
        }
        loot[i] = arr[i]+temp;
        
        if(loot[i] > result)
            result = loot[i];
    }
    
    return result;
}


int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int result = getMaxMoney(arr,n);
	cout<<result<<endl;
	return 0;
}
