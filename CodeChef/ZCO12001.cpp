#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	
	int seq[n];
	for(int i=0;i<n;i++)
		scanf("%d",&seq[i]);
		
	int o_bracket = 0,c_bracket = 0;
	int ct = 0;
	
	
	int nesting_depth = 0,max_first_pos = -1,max = 0;
	
	for (int i=0;i<n;i++){
		
		if (seq[i] ==  1){
			o_bracket += 1;
			if (ct == 0)
			{
				max_first_pos = i;
			}
			ct++;
		}
		
		if (seq[i] == 2){
			c_bracket += 1;
			ct++;
		}
		
		if (o_bracket == c_bracket){
			int k = (o_bracket+c_bracket)/2;
			
			if (k > nesting_depth){
				nesting_depth = k;
			}
			
			if (ct > max){
				max = ct;
				ct = 0;
			}
			o_bracket = 0;
			c_bracket = 0;
		}
	}
	
	printf(" nesting depth : %d ",nesting_depth);
	printf(" \n max number of sequence : %d ",max);
	
	return 0;
}
