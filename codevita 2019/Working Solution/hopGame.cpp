#include<bits/stdc++.h>
using namespace std;

int maxScore(int *arr,int n,int pos,bool isThrice,bool isTwice,bool doneThrice)
{
	if(pos >= n)
		return 0;
		
	int maxSc = 0;
	int a=0,b=0,c=0;
	
	a = maxScore(arr,n,pos+1,false,false,doneThrice);
	b = maxScore(arr,n,pos+1,false,true,doneThrice);
	
	if(doneThrice == false)
		c = maxScore(arr,n,pos+3,true,false,true);
	
	int kc = arr[pos];
	
	if(isThrice)
		kc = 3*kc;
	
	if(isTwice)
		kc = 2*kc;
	
	int temp1 = a + kc;
	int temp2 = b ;
	int temp3 = c + kc;
	
	maxSc = max(temp1,max(temp2,temp3));
	return maxSc;
}

int main()
{
	int n;
	cin>>n;
	
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		
		if(i!=n-1)
		{
			char ch;
			cin>>ch;
		}	
		arr[i] = a;
	}	
	
	int res1 = maxScore(arr,n,0,false,false,false);
	int res2 = maxScore(arr,n,2,true,false,true);
	
	if(res1 > res2)
		cout<<res1;
	else
		cout<<res2;
}
