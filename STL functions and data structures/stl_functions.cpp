#include<algorithm>
#include<iostream>

using namespace std;

struct Interval{
	int st;
	int et;
};

bool compare(Interval i1,Interval i2)
{
	return i1.st<i2.st;
}

void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {23,234,3,21,232,0,-12,32,2,67};
	int n = sizeof(arr)/sizeof(int);
	
	// Sorting arr in descending order
	sort(arr,arr+n,greater<int>());
	printArray(arr,n);
	
	// Sorting arr in ascending order
	sort(arr,arr+n);
	printArray(arr,n);
	
	// Sorting Intervals using comparator functions
	Interval time_schedule[] = {{2,1},{19,20},{-1,0},{1,9}};
	sort(time_schedule,time_schedule+4,compare);
	for(int i=0;i<4;i++)
	{
		cout<<"{"<<time_schedule[i].st<<","<<time_schedule[i].et<<"}"<<" ";
	}
	cout<<endl;
	
	// using binary_search in a sorted array 
	int search_element = 21;
	bool status = binary_search(arr,arr+n,search_element);
	
	if(status)
		cout<<"Element Found"<<endl;
	else
		cout<<"Element Not Found"<<endl;
		
	return 0;
}
