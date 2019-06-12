#include<bits/stdc++.h>
using namespace std;
#define max 1000001

int factor[max] = {0};

void fillFactor()
{
	// this method will fill the factor array with smallest possible prime divisor/factor of a number
	factor[1] = 1;
	for(int i = 2;i<max;i++)
		factor[i] = i;
		
	for(int j=2;j*j < max;j++)
	{
		if(factor[j] == j)
		{
			for(int i=j*j;i< max;i+=j)
			{
				if(factor[i] == i)
					factor[i] = j;
			}
		}
	}
}


int getNumberOfFactors(int n)
{
	if(n == 1)
		return 1;
	
	int ans = 1;
	int c = 1;
	int b = factor[n];
	int j = n / b;
	
	
	while(j != 1)
	{ 
		if(factor[j] == b)
		{
			c+=1;	
		}	
		else
		{
			ans = ans * (c+1);
			c = 1;
			b = factor[j];
		}
		j = j/b;
	}
	ans = ans * (c+1);
	
	return ans;	
}

// complexity of this is - O(N*log(max(number))

int main()
{
	int arr[] = {23,24,35,7,220};
	int l = sizeof(arr)/sizeof(int);
	fillFactor();
	for(int i=0;i<l;i++)
	{
		cout<<getNumberOfFactors(arr[i])<<endl;
	}
}
