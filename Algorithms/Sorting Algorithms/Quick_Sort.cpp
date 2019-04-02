#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[],int st,int ed)
{
	int pivot = arr[st];
	int countSmaller = 0;
	for(int i=st+1;i<=ed;i++)
	{
		if(arr[i]<=pivot)
			countSmaller++;
	}
	
	int pivotIndex = st+countSmaller;
	arr[st] = arr[pivotIndex];
	arr[pivotIndex] = pivot;
	
	int ltr = st;
	int rtr = ed;
	while(ltr<pivotIndex && rtr>pivotIndex)
	{
		if(arr[ltr] <= pivot)
			ltr++;
		else if(arr[rtr] > pivot)
			rtr--;
		else
		{
			int temp = arr[ltr];
			arr[ltr] = arr[rtr];
			arr[rtr] = temp;
			ltr++;
			rtr--;
		}
	}
	
	return pivotIndex;
	
}

void quickSort(int arr[],int st,int ed)
{
	if(st < ed)
	{
		int c = partition(arr,st,ed);
		quickSort(arr,st,c-1);
		quickSort(arr,c+1,ed);
	}
	return;
}


int main()
{
	int arr[] = {5,10,23,1,0,7,-1};
	int l = sizeof(arr)/sizeof(int);
	quickSort(arr,0,l-1);
	
	cout<<"Sorted Array : ";
	for(int i=0;i<l;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
