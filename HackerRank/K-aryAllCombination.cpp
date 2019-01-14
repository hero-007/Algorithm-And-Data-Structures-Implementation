#include <bits/stdc++.h>
#define max 100

using namespace std;

void karyCombination(int n,char *a,int k)
{
	if (n < 1)
		printf("%s\n",a);
	else{
		for(int i=0;i<k;i++){
		a[n-1] = i+48;
		karyCombination(n-1,a,k);
		a[n-1] = i+48;
		karyCombination(n-1,a,k);
	}
	}
}

int main()
{
	int k,n;
	printf("Enter the value of k : ");
	scanf("%d",&k);
	printf("Enter the length of the array : ");
	scanf("%d",&n);
	
	char arr[n];
	karyCombination(n,arr,k);
	return 0;
}
