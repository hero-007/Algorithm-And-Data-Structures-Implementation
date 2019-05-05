/**
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.

Note : Return 0, if change isn't possible.

Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V

Output Format
Line 1 :  Number of ways i.e. W

Constraints :
1<=n<=10
1<=V<=1000

Sample Input 1 :
3
1 2 3
4

Sample Output
4

Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

**/

#include<bits/stdc++.h>
using namespace std;

int getResult(int denominations[], int numDenominations, int value,int **temp)
{
    if(numDenominations == 0)
        return 0;
    
    if(value == 0)
        return 1;
    
    if(value < 0)
        return 0;
    if(temp[value][numDenominations] > -1)
        return temp[value][numDenominations];
    
    int first = getResult(denominations,numDenominations,value-denominations[0],temp);
    int second = getResult(denominations+1,numDenominations-1,value,temp);
    temp[value][numDenominations] = first+second;
    
    return first+second;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

    int **temp = new int*[value+1];
    for(int i=0;i<=value;i++)
    {
        temp[i] = new int[numDenominations+1];
        for(int j=0;j<=numDenominations;j++)
            temp[i][j] = -1;
    }
    
    return getResult(denominations,numDenominations,value,temp);
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}

