#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag = 0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		
		if (flag == 0)
			break;
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
		
	bubble_sort(a,n);
	
	printf("Array after sorting : ");
	for(int j=0;j<n;j++)
		printf("%d ",a[j]);
	
	
	return 0;
}
