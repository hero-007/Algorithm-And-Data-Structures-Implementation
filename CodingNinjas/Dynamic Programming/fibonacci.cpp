#include<bits/stdc++.h>
using namespace std;

// Implementing fibonacci without dynamic programming - O(2^n)
int fib_without_dp(int n)
{
	// Implementing fibonacci without DP
	// This implementation takes O(2^n) time
	
	if(n == 0 || n == 1)
		return n;
	return fib_without_dp(n-1) + fib_without_dp(n-2);
}

// Implementing fibonacci using Dynamic Programming - reduces time complexity to O(n)
int fib_with_dp(int n,int *arr)
{
	if(n==0 || n==1)
		return n;
	
	if(arr[n] > 0)
		return arr[n];
		
	int output = fib_with_dp(n-1,arr) + fib_with_dp(n-2,arr);
	arr[n] = output;
	return output;
}

// Implementing fibonacci Iteratively - this also reduces the complexity to O(n)
int fib_iteratively(int n)
{
	if(n == 0 || n == 1)
		return n;
	
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2];
		
	int result = arr[n];
	delete []arr;
	return result;
}


// Implementing fibonacci Iteratively - reduce space complexity by using variables instead of array 
int fib_iterative_reduced(int n)
{
	if(n == 0 || n == 1)
		return n;
		
	int a = 0;
	int b = 1;
	
	int count = 2;
	
	while(count <= n)
	{
		int temp = a+b;
		a = b;
		b = temp;
		count++;
	}
	
	return b;
}




int main()
{
	int n = 20;
	int *arr = new int[n+1];
	for(int i=0;i<=n;i++)
		arr[i] = 0;
		
	cout<<"fib_without_dp : "<<fib_without_dp(n)<<endl;
	cout<<"fib_with_dp : "<<fib_with_dp(n,arr)<<endl;
	cout<<"fib_iteratively : "<<fib_iteratively(n)<<endl;
	cout<<"fib_iterative_reduced : "<<fib_iterative_reduced(n)<<endl;
	return 0;
}
