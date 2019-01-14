#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min = j;	
		}
		
		if (min != i)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}

int main()
{
	
	int n;
	printf("Enter the length of the array : ");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the array elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	selection_sort(a,n);
	
	printf("Array after sorting : ");
	for(int j=0;j<n;j++)
		printf("%d ",a[j]);
	
	return 0;
	
}
