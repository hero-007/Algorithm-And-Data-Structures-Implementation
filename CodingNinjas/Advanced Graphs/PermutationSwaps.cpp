/**
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.

Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.

Constraints:
1 = T = 10
2 = N = 100000
1 = M = 100000
1 = Pi, Qi = N. Pi and Qi are all distinct.
1 = ai < bi = N

SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4

SAMPLE OUTPUT
NO 
YES
**/

#include<bits/stdc++.h>
using namespace std;

void singleConnectedComponent(vector<int>* adj_list,vector<int> &temp,bool *visited,int start)
{
	visited[start] = true;
	temp.push_back(start);
	
	vector<int> t = adj_list[start];
	for(int i=0;i<t.size();i++)
	{
		int a = t[i];
		if(visited[a] == true )
			continue;
			
		singleConnectedComponent(adj_list,temp,visited,a);
	}
}

vector<vector<int> > getConnectedComponents(vector<int>* adj_list,int n)
{
	vector<vector<int> >output;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	for(int j=0;j<n;j++)
	{
		if(visited[j] == false)
		{	
		vector<int> temp;
		singleConnectedComponent(adj_list,temp,visited,j);
		output.push_back(temp);
		}
	}
	
	delete []visited;
	return output;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	
	vector<int> *adj_list = new vector<int>[n];
	
	int *value1 = new int[n];
	for(int k=0;k<n;k++)
	{
		int b;
		cin>>b;
		value1[k] = b;
	}
	
	int *value2 = new int[n];
	
	for(int k=0;k<n;k++)
	{
		int b;
		cin>>b;
		value2[k] = b;
	}
	
	// create the adjacency list 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		
		adj_list[a-1].push_back(b-1);
		adj_list[b-1].push_back(a-1);
	}
	
	vector<vector<int> > output = getConnectedComponents(adj_list,n);
	
	// printing the content of output vector

	int l = output.size();
	int chr = -1;
	
	vector<vector<int> > comp_1;
	vector<vector<int> > comp_2;
	for(int i=0;i<l;i++)
	{
		vector<int> tk = output[i];
		vector<int> *temp1 = new vector<int>();
		vector<int> *temp2 = new vector<int>();
		
		for(int j=0;j<tk.size();j++)
		{
			int a = tk[j];
			temp1->push_back(value1[a]);
			temp2->push_back(value2[a]);
		}
		

		sort(temp1->begin(),temp1->end());
		sort(temp2->begin(),temp2->end());
		
		int rt = temp1->size();
        vector<int> :: iterator it1 = temp1->begin();
        vector<int> :: iterator it2 = temp2->begin();
        
        while(it1 != temp1->end())
        {
            if(*it1 != *it2)
            {
                chr = 1;
                break;
            }
            it1++;
            it2++;
        }
		
		
		if(chr == 1)
			break;
	}
	
	if(chr == 1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	}
	return 0;
}
