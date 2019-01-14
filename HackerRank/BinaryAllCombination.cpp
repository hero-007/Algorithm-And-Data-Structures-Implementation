#include <bits/stdc++.h>
#define max 100

using namespace std;

void BinaryCombination(int n,char *a)
{
	if (n < 1)
		printf("%s\n",a);
	else{
		a[n-1] = '0';
		BinaryCombination(n-1,a);
		a[n-1] = '1';
		BinaryCombination(n-1,a);
	}
}

int main()
{
	int k;
	printf("Enter the value of k : ");
	scanf("%d",&k);
	
	char arr[k];
	BinaryCombination(k,arr);
	return 0;
}
