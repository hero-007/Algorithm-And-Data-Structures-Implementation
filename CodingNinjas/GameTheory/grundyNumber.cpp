/**
Calculate Grundy Number

Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?

Input Format
An Integer 'n'

Output Format
Grundy Number(n)

Sample Input 1 -
10
Sample Output 1-
0

**/
#include<bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> m)
{
    int a = 0;
    while(true)
    {
        if(m.find(a) == m.end())
            return a;
        a++;
    }
}

int grundyNumber(int n)
{
    if(n == 0)
        return 0;
    
    int g1 = grundyNumber(n/2);
    int g2 = grundyNumber(n/3);
    int g3 = grundyNumber(n/6);
    
    unordered_set<int> s;
    s.insert(g1);
    s.insert(g2);
    s.insert(g3);
    
    int m = mex(s);
    return m;
}

int main() {
    int n;
    cin>>n;
    
    int gNum = grundyNumber(n);
    cout<<gNum<<endl;
    
    return 0;
}
