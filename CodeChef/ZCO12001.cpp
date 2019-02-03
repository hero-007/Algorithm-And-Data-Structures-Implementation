#include<iostream>
#include<stack>

using namespace std;


void stringInfo(int *s,int& depth,int& depth_first_pos,int& max_symbol,int& starting_pos,int si)
{
	stack<int> stk;
	int l = si;
	
	int max_depth = 0;
	int f_depth_pos = 0;
	int md_first = 0;
	int dep = 0;
	
	int count_max = 0, temp_max = 0;
	int f_count_pos = 0, temp_count_pos = 0;
	
	for(int i=0;i<l;i++)
	{
		int c = s[i];
		bool st = stk.empty();
		if (st == true || i == l-1)
		{
			
			if (temp_max > count_max){
				count_max = temp_max;
				f_count_pos = temp_count_pos;
			}
			
			if ((temp_max+1 > count_max) && i == l-1){
				count_max = temp_max+1;
				f_count_pos = temp_count_pos;
			}
			
			temp_count_pos = i+1;
			temp_max = 0;
		}
		
		if(c==1){
			stk.push(c);
			dep++;
			md_first = i+1;
			
			if (dep > max_depth)
			{
				max_depth = dep;
				f_depth_pos = md_first;
			}
			
			temp_max++;
		}
		else
		{
				stk.pop();
				dep--;
				temp_max++;
		}
	}
	
	depth = max_depth;
	depth_first_pos = f_depth_pos;
	max_symbol = count_max;
	starting_pos = f_count_pos;
}

int main()
{
	int n;
	scanf("%d",&n);
	int k[n];
	
	for(int j=0;j<n;j++)
		cin>>k[j];
		
	int depth = 0,first_pos_depth = 0;
	int max_symbol = 0,max_symbol_first_pos = 0;
	
	stringInfo(k,depth,first_pos_depth,max_symbol,max_symbol_first_pos,n);
	
	cout<<depth<<" "<<first_pos_depth<<" "<<max_symbol<<" "<<max_symbol_first_pos<<endl;
	
	return 0;
}
