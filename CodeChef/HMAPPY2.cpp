#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// Compute GCD to find the LCM of A and B using euclid's algorithm
int gcd(int a,int b)
{
	if (a == 0)
		return b;
	else 
		return gcd(b%a,a);
}

unsigned long long find_lcm(int a,int b)
{
	int max;
	int min = (a>b)?b:a;
	
	if (min == a)
		max = b;
	else
		max = a;
	
	int gcd_num = gcd(min,max);
	unsigned long long lcm = (a*b)/gcd_num;
	
	return lcm;
}

int main()
{
	int t,a,b;
	long long int k,n;
	
	scanf("%d",&t);
	while(t-- != 0)
	{
		scanf("%llu%d%d%llu",&n,&a,&b,&k);
		unsigned long long count_a = floor(n/a);
		unsigned long long count_b = floor(n/b);
		
		//cout<<"count_a : "<<count_a<<" count_b : "<<count_b<<endl;
		
		unsigned long long lcm = find_lcm(a,b);
		unsigned long long count_c = floor(n/lcm);
		
		//cout<<"count_c : "<<count_c<<endl;
		
		unsigned long long result = (count_a + count_b) - (count_c*2);
		
		//cout<<"result : "<<result<<endl;
		
		if(result >= k)
			cout<<"Win"<<endl;
		else
			cout<<"Lose"<<endl;
	}
	
	return 0;
}

