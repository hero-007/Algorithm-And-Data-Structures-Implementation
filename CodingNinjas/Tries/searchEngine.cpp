/**
Search Engine

Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.

INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.

OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.

CONSTRAINTS
1 = n, weight, len(s), len(t) = 10^6
1 = q = 10^5
total length of all strings in database entries = 10^6
total length of all query strings = 10^6

SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker

SAMPLE OUTPUT
10

**/
#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public:
	trieNode ** children;
	int weight;
	
	trieNode(){
		children = new trieNode* [26];
		for(int i=0;i<26;i++)
		{
			children[i] = NULL;
		}
		weight = 0;
	}
};

void insert(string s,int weight,trieNode *root)
{
	trieNode *head = root;
	
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		int idx = s[i]-'a';
		if(!head->children[idx])
		{
			head->children[idx] = new trieNode();
		}
		if(head->weight < weight)
		{
			head->weight = weight;
		}
		head = head->children[idx];
	}
}

int searchBiggest(string st,trieNode *head)
{
	trieNode *root = head;
	int val = -1;
	
	for(int i=0;i<st.length();i++)
	{
		int a = st[i]-'a';
		
		if(root->children[a] == NULL)
		{
			return -1;
		}
		
		root = root->children[a];
		val = root->weight;
	}
	
	return val;
}

int main()
{
	int n,q;
	cin>>n>>q;
	
	trieNode *root = new trieNode();
	for(int i=0;i<n;i++)
	{
		string st;
		cin>>st;
		int w;
		cin>>w;
		
		insert(st,w,root);
	}
	
	while(q--)
	{
		string pt;
		cin>>pt;
		
		int res = searchBiggest(pt,root);
		cout<<res<<endl;
	}
	return 0;
}
