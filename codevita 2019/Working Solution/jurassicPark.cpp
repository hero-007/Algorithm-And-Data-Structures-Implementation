#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define size 1001
#define x first
#define y second

vector<vector<int> > gate1(size,vector<int>(size,INT_MAX));
vector<vector<int> > gate2(size,vector<int>(size,INT_MAX));
vector<vector<int> > gate3(size,vector<int>(size,INT_MAX));
vector<vector<int> > cage(size,vector<int>(size,INT_MAX));
int r,c;

char park[size][size];
pair<int,int> g1,g2,g3,den;

bool checkValidGate(int x,int y)
{
	if(x>=1 && x<=r && y>=1 && y<=c)
	{
		if(park[x][y] == 'G')
			return true;
	}
	return false;
}

bool checkValidCage(int x,int y)
{
	if(x>=1 && x<=r && y>=1 && y<=c)
	{
		if(park[x][y] == 'G' || park[x][y] == 'M')
			return true;
	}
	return false;
}

void fillGate(pair<int,int> g,vector<vector<int> > &gate)
{
	int dir_x[] = {-1,0,1,0};
	int dir_y[] = {0,1,0,-1};
	
	bool visited[r+1][c+1];
	memset(visited,false,sizeof(visited));
	queue<pair<pair<int,int>,int> > q;
	
	q.push(make_pair(g,0));
	visited[g.x][g.y] = true;
	gate[g.x][g.y] = 0;
	
	while(!q.empty())
	{
		pair<pair<int,int> ,int> curr = q.front();
		int curr_x = curr.x.x;
		int curr_y = curr.x.y;
		gate[curr_x][curr_y] = curr.y;
		
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int n_x = curr_x + dir_x[i];
			int n_y = curr_y + dir_y[i];
			
			bool status = checkValidGate(n_x,n_y);
			if(status == true && visited[n_x][n_y] == false)
			{
				int n_weight = curr.y + 1;
				pair<pair<int,int>,int> temp = make_pair(make_pair(n_x,n_y),n_weight);
				visited[n_x][n_y] = true;
				q.push(temp);
			}
		}
	}
}

void fillCage(pair<int,int> g)
{
	int dir_x[] = {-1,0,1,0};
	int dir_y[] = {0,1,0,-1};
	
	bool visited[r][c];
	memset(visited,false,sizeof(visited));
	queue<pair<pair<int,int>,int> > q;
	
	q.push(make_pair(g,0));
	visited[g.x][g.y] = true;
	cage[g.x][g.y] = 0;
	
	while(!q.empty())
	{
		pair<pair<int,int> ,int> curr = q.front();
		int curr_x = curr.x.x;
		int curr_y = curr.x.y;
		cage[curr_x][curr_y] = curr.y;
		
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int n_x = curr_x + dir_x[i];
			int n_y = curr_y + dir_y[i];
			
			bool status = checkValidCage(n_x,n_y);
			if(status == true && visited[n_x][n_y] == false)
			{
				int n_weight = curr.y + 1;
				pair<pair<int,int>,int> temp = make_pair(make_pair(n_x,n_y),n_weight);
				visited[n_x][n_y] = true;
				q.push(temp);
			}
		}
	}
}

void print(vector<vector<int> > gh)
{
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++){
			if(gh[i][j] == INT_MAX)
				cout<<"#"<<" ";
			else
				cout<<gh[i][j]<<" ";
		}
		cout<<endl;
	}
}
signed main()
{
	// gate1 - minimum distance from any grassland to reach gate 1
	// gate2 - minimum distance from any grassland to reach gate 2
	// gate3 - minimum distance from any grassland to reach gate 3
	// cage - minimum distance from cage to reach any reachable grassland (gate 1,gate 2,gate 3)
	
	cin>>r>>c;
	cin>>g1.x>>g1.y;
	cin>>g2.x>>g2.y;
	cin>>g3.x>>g3.y;
	cin>>den.x>>den.y;
	
	int total_grass = 0;
	// fill the park matrix
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>park[i][j];
			if(park[i][j] == 'G')
				total_grass += 1;
		}
	}
	
	// Apply BFS to fill gate1, gate2, gate3
	
	fillGate(g1,gate1);
	fillGate(g2,gate2);
	fillGate(g3,gate3);
	
	// Apply BFS to fill cage
	fillCage(den);
	
	int count_Safe = 0;
	
	
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(park[i][j] == 'M' || park[i][j] == 'W' || (i==den.x && j==den.y))
				continue;
				
			if(park[i][j] == 'G' && (gate1[i][j] < cage[g1.x][g1.y] || gate2[i][j] < cage[g2.x][g2.y] || gate3[i][j] < cage[g3.x][g3.y] || cage[i][j] == INT_MAX))
				count_Safe++;
		}
	}
	
	print(gate1);
	cout<<endl;
	print(gate2);
	cout<<endl;
	print(gate3);
	cout<<endl;
	print(cage);
	cout<<endl;
	printf("%.2f", 100.0f * count_Safe / total_grass);
	return 0;
}

/**
4 6
1 6 3 6 4 6 3 4
W M G G G G
M G W G M M
G W G G G G
W G W M W G
**/
