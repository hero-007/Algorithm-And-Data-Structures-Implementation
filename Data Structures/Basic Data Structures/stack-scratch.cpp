#include<bits/stdc++.h>
using namespace std;

void push(int *stk,int *top,int n,int x)
{
	
	if (*top == n-1)
	{
		//Checking for the Overflow condition 
		printf("Stack Overflow\n");
		return;
	}
	else{
		// PUSH element x into the Stack
		*top = *top +1;
		stk[*top] = x;
	}
}

void pop(int *stk,int *top)
{
	
	if (*top == -1)
	{
		// Checking for the underflow condition 
		printf ("Stack Underflow\n");
		return ;
	}
	else
	{
		// POP an element from the Stack 
		int p = stk[*top];
		*top = *top - 1;
		printf("%d is poped \n",p);
	}
}

void display_stack(int *stk,int top)
{
	if (top == -1)
	{
		printf("Stack is Empty\n");
		return;
	}
	for(int i=0;i<=top;i++)
	{
		printf("%d ",stk[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	
	printf("Enter the size of the stack : ");
	scanf("%d",&n);
	
	int stk[n],choice,top = -1;
	
	while (true)
	{
		printf("Choose an option :\n1: PUSH\n2: POP\n3: DISPLAY STACK\n4: EXIT\n\nCHOICE : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				int x;
				printf("Enter the element to push : ");
				scanf("%d",&x);
				push(stk,&top,n,x);
				break;
			case 2:
				pop(stk,&top);
				break;
			case 3:
				display_stack(stk,top);
				break;
			case 4:
				goto A;
			default: printf("Choose the correct option : ");
		}
	}
	
	A:printf("\nThank You\n");
	return 0;
}
