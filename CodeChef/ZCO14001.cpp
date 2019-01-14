#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n,h;
	cin>>n>>h;
	
	// pick command will be ignored if the crane already has a box
	// drop command will be ignored if the crane has no box
	// drop command will be ignored if the level of the stack is already full
	
	int stk[n];
	for(int i=0;i<n;i++)
		cin>>stk[i];
		
	int cmd = -1,crane = 0,crane_pos = 0;
	while (cmd != 0){
		cin>>cmd;
		
		if (cmd == 0)
			continue;
		
		if (cmd == 1 && crane_pos != 0)
		{
			crane_pos -= 1;
		}
		if (cmd == 2 && crane_pos != (n-1))
		{
			crane_pos += 1;
		}
		if (cmd == 3 && crane != 1)
		{
			if (stk[crane_pos]>0)
			{
				crane = 1;
				stk[crane_pos] -= 1;
			}
		}
		if (cmd == 4 && crane != 0)
		{
			if (stk[crane_pos]<h)
			{
				crane = 0;
				stk[crane_pos] += 1;
			}
		}
	}
	
	for(int j=0;j<n;j++)
		cout<<stk[j]<<" ";	
	
	return 0;
}
