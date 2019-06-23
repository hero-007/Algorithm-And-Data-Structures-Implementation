/**  Extracting comma seprated integers | number of intergers is also given  **/

// Genrally Codevita format input 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		
		arr[i] = num;
		
		if(i != n-1)
		{
			// handling comma in the input
			char ch;
			cin>>ch;	
		}
	}
	
	/**  print all the elements of the arr  **/
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
