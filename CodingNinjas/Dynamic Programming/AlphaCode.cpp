/**
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.

Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"

Sample Input:
25114
1111111111
3333333333
0

Sample Output:
6
89
1
**/

#include<bits/stdc++.h>
using namespace std;

/**
There are 3 different ways of doing this problem -
1 - recursive and naive solution - this will take O(2^n) time
2 - recursive solution using DP - this will take O(n) time
3 - iterative solution using DP - this will take O(n) time
**/


// 1 ---- Naive solution which takes - O(2^n) time
int alphaCode_1(int *arr,int size)
{
	if(size == 0)
		return 1;
	
	if(size == 1)
		return 1;
		
	int output = alphaCode_1(arr,size-1);
	
	if((arr[size-2]*10+arr[size-1]) <= 26)
		output += alphaCode_1(arr,size-2);
	
	return output;
}

// 2 ---- Complexity of the above code can be reduced to O(n) using DP
int alphaCode_2(int *arr,int size,int *output)
{
	if(size == 0)
		return 1;
	if(size == 1)
		return 1;
		
	if(output[size] > 0)
		return output[size];
	
	int result = alphaCode_2(arr,size-1,output);
	if((arr[size-2]*10 + arr[size-1]) <= 26)
		result += alphaCode_2(arr,size-2,output);
		
	output[size] = result;
	return output[size];
}

// 3 ---- There is an iterative solution for this problem using Dynamic Programming 
int alphaCode_3(int *arr,int size)
{
	if(size == 0 || size == 1)
		return 1;
	
	int *output = new int[size+1];
	output[0] = 1;
	output[1] = 1;
	
	for(int i=2;i<=size;i++)
	{
		output[i] = output[i-1];
		if((arr[i-2]*10 + arr[i-1])<= 26)
			output[i] += output[i-2];
	}
	
	int temp = output[size];
	delete []output;
	return temp;
}


int main()
{
	int n;
	cout<<"Enter the length of the code : ";
	cin>>n;
	
	int arr[n];
	int output[n+1] = {0};
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int result_1 = alphaCode_1(arr,n);
	int result_2 = alphaCode_2(arr,n,output);
	int result_3 = alphaCode_3(arr,n);
	
	
	cout<<"Result 1 - "<<result_1<<endl;
	cout<<"Result 2 - "<<result_2<<endl;
	cout<<"Result 3 - "<<result_3<<endl;
	return 0;
}
