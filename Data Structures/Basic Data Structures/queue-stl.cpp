#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<string> q;
	
	q.push("Hello");
	q.push("My");
	q.push("Name");
	q.push("is");
	q.push("Saitama");
	
	printf("Size of the queue is : %d\n",q.size());
	cout<<"front element of the queue is : "<<q.front()<<endl;
	cout<<"rear element of the queue is : "<<q.back()<<endl;
	
	q.pop();
	q.pop();
	
	printf("Queue after removing two elements is : ");
	while(q.empty() == false)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
	return 0;
}
