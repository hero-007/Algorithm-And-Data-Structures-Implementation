#include <bits/stdc++.h>

// Implemented using the concept of counting sort //

using namespace std;

int main()
{
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	
	int t_sum = n1+n2+n3;
	int ct = 0;
	int finl_list[t_sum];
	
	int max = 0;
	for(int i=0;i<t_sum;i++){
		scanf("%d",&finl_list[i]);
		
		if (finl_list[i]>max)
			max = finl_list[i];
	}
		
	int c_array[max] = {0};
	
	for(int k=0;k<t_sum;k++){
		c_array[finl_list[k]]+=1;
		
		if(c_array[finl_list[k]] == 2)
			ct += 1;
	}
	
	printf("%d\n",ct);
	for(int j=0;j<max;j++){
		if(c_array[j] >= 2){
			printf("%d\n",j);
		}
	}
	
	
	return 0;
}
