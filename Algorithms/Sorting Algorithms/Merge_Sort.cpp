#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	
	int left[n1+1],right[n2+1];
	
	for(int i=1;i<n1;i++)
}
void merge_sort(int *a,int p,int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main()
{
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	n+=1;
	
	int arr[n];
	
	printf("Enter the array elements below :\n");
	for(int i=1;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(arr,1,n-1);
	return 0;
}
