#include<bits/stdc++.h>
using namespace std;

void enqueue(int *stk,int *front,int *rear,int n,int x)
{
	if(((*rear==n-1)&&(*front==0)) || (*rear+1 == *front))
	{
		printf("Overflow\n");
		return;
	}
	else{
		if ((*front>0) && *rear == n-1)
			*rear = 0;
		else if (*front == -1 && *rear == -1)
			*front = *rear = 0;
		else
			*rear+=1;
		stk[*rear] = x;
		
		printf("%d has been inserted to queue",x);
	}
}

void dequeue(int *stk,int *front,int *rear,int n)
{
	
	if (*front == *rear+1)
	{
		// Checking for the underflow condition 
		printf ("Underflow\n");
		return ;
	}
	else
	{
		// delete an element from the queue
		int p = stk[*front];
		stk[*front] = -999;
		if ((*front > *rear) && (*front == n-1))
			*front = 0;
		else
			*front +=1;
		printf("%d has been removed  \n",p);
	}
}

void display_queue(int *stk,int front,int rear,int n)
{
	printf("Current status of the queue : ");
	
	while(front != rear)
	{
		printf("%d ",stk[front]);
		
		if ((front == n-1)&&(rear < front))
			front = 0;
		else
			front +=1;
	}
	printf("%d\n",stk[front]);
}

int main()
{
	int n;
	
	printf("Enter the size of the queue : ");
	scanf("%d",&n);
	
	int stk[n],choice,front = -1,rear = -1;
	
	while (true)
	{
		printf("Choose an option :\n1: ENQUEUE\n2: DEQUEUE\n3: DISPLAY QUEUE\n4: EXIT\n\nCHOICE : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				int x;
				printf("Enter the element to insert in queue : ");
				scanf("%d",&x);
				enqueue(stk,&front,&rear,n,x);
				break;
			case 2:
				dequeue(stk,&front,&rear,n);
				break;
			case 3:
				display_queue(stk,front,rear,n);
				break;
			case 4:
				goto A;
			default: printf("Choose the correct option : ");
		}
	}
	
	A:printf("\nThank You\n");
	return 0;
}
