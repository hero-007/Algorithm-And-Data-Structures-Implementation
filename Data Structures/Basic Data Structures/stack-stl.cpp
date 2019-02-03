#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack<int> mystack;
	
	mystack.push(0);
	mystack.push(1);
	mystack.push(2);
	
	// Print the total number of elements in the stack
	printf("size of the stack : %d\n",mystack.size());
	
	// Printing the content of the stack and there respective index values
	
	while(mystack.empty() == false)
	{
		printf("%d \n",mystack.top());
    	mystack.pop();
	}	
	
	return 0;
}
