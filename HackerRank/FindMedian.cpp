/* implementing this question using merge sort algorithm */

#include <bits/stdc++.h>
using namespace std;

void merge(int *a,int p,int q,int r){
	
	int n1 = q-p+1;
	int n2 = r-q;
	
	int left[n1],right[n2];
	
	for(int i=0;i<n1;i++)
		left[i] = a[p+i-1];
		
	for(int j=0;j<n2;j++)
		right[j] = a[q+j];
		
	left[n1-1] = 99999;
	right[n2-1] = 99999;
	
	int x=0,y=0;
	for(int k=p;k<q;k++)
	{
		if(left[x]<=right[y])
		{
			a[k] = left[x];
			x = x+1;
		}
		else{
			a[k] = right[y];
			y = y+1;
		}
	}
}

void merge_sort(int *a,int p,int r)
{
	if (p<r){
		int q = (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	merge_sort(arr,0,n-1);
	
	int k = n/2;
	printf("%d",arr[k]);
	
	printf("\nArray After sorting : ");
	for(int y=0;y<n;y++)
		printf("%d ",arr[y]);
	
	return 0;
}
