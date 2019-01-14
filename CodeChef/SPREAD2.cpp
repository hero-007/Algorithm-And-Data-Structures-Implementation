#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t=0;
	scanf("%d",&t);
	
	while(t-- > 0)
	{
		
		int n=0;
		scanf("%d",&n);
		int a[n];
		
		scanf("%d",&a[0]);
		for(int i=1;i<n;i++){
			scanf("%d",&a[i]);
			a[i] = a[i]+a[i-1];
			
			if (a[i] > n)
				a[i] = n;
		}
		
		int told = 0;
		int current_limit = 0;
		int days = 0;
		
		while (told < n)
		{
			told = (a[current_limit] + current_limit)+1;
			current_limit = told-1;
			days += 1;
		}
			
		printf("%d\n",days);
	}
	
	return 0;
}
