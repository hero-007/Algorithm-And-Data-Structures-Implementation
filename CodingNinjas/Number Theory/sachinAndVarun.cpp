/**
Sachin And Varun Problem

Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.

Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.

Output Format:
For each test case, print the answer in a separate line.

Constraints:
1 =T= 10^5

1 = a < b = 10^9

0=d=10^9

Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2

Explanation
Test case 1: 7 can only be achived by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.

**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet{
    public:
        ll x;
        ll y;
        ll gcd;
};

Triplet extendedEuclid(ll a,ll b)
{
    if(b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    
    Triplet smallResult = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallResult.gcd;
    ans.x = smallResult.y;
    ans.y = smallResult.x - (a/b)*smallResult.y;
    
    return ans;
}

ll mulModInverse(ll a,ll b)
{
    ll x = extendedEuclid(a,b).x;
    return (x%b + b)%b;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        
        if(d%g)
        {
        	cout<<0<<endl;
        	continue;
		}
		
		if(d == 0)
		{
			cout<<1<<endl;
			continue;
		}
        ll g = __gcd(a,b);
        a /= g;
        b /= g;
        d /= g;
        
        ll y1 = ((d%a)*mulModInverse(b,a))%a;
        ll firstValue = d/b;
        
        if(d < y1*b)
        {
        	cout<<0<<endl;
        	continue;
		}
		ll n = (firstValue - y1)/a;
		cout<<n+1<<endl;
    }
    
    return 0;
}
