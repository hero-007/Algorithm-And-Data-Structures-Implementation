#include<queue>
#include<iostream>
using namespace std;

void showpq(priority_queue<int> pq)
{
	while(!pq.empty())
	{
		int x = pq.top();
		cout<<x<<" ";
		pq.pop();
	}
}

int main()
{
	int arr[] = {12,24,34,50,34,70};
	
	priority_queue<int> pq;
	for(int i=0;i<6;i++)
		pq.push(arr[i]);	// O(nlogn) time 
		
	showpq(pq);
	
	return 0;
}
