#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
using namespace std;
vector<vector<int> > dist1(1009, vector<int>(1009, INT_MAX));
vector<vector<int> > dist2(1009, vector<int>(1009, INT_MAX));
vector<vector<int> > dist3(1009, vector<int>(1009, INT_MAX));
vector<vector<int> > dist4(1009, vector<int>(1009, INT_MAX));
int  r, c;
char __map[1009][1009]; 
pair<int ,int> g1, g2, g3, sher;
   
void calcDist(pair<int, int> src, vector<vector<int> > &dist){
    int i, j;
    pair<int, int> frnt;
    queue<pair<int, int> > que;
    dist[src.X][src.Y] = 0;
    que.push({src.X, src.Y});
    bool visited[r+9][c+9];
    memset(visited, false, sizeof visited);
    visited[src.X][src.Y] = true;
    while(!que.empty()){
        frnt = que.front(); que.pop();
        i = frnt.X; j = frnt.Y;
        if(i-1 > 0 and
           __map[i-1][j] == 'G' and
           !(i-1 == sher.X and j == sher.Y) and
           !visited[i-1][j]
          ){
            dist[i-1][j] = min(dist[i-1][j], dist[i][j] + 1);
            visited[i-1][j] = true;
            que.push({i-1, j});
        }
        if(i+1 <= r and
           __map[i+1][j] == 'G' and
           !(i+1 == sher.X and j == sher.Y) and
           !visited[i+1][j]
          ){
            dist[i+1][j] = min(dist[i+1][j], dist[i][j] + 1);
            visited[i+1][j] = true;
            que.push({i+1, j});
        }
        if(j-1 > 0 and
           __map[i][j-1] == 'G' and
           !(i == sher.X and j-1 == sher.Y) and
           !visited[i][j-1]
          ){
            dist[i][j-1] = min(dist[i][j-1], dist[i][j] + 1);
            visited[i][j-1] = true;
            que.push({i, j-1});
        }
        if(j+1 <= c and
           __map[i][j+1] == 'G' and
           !(i == sher.X and j+1 == sher.Y) and
           !visited[i][j+1]
          ){
            dist[i][j+1] = min(dist[i][j+1], dist[i][j] + 1);
            visited[i][j+1] = true;
            que.push({i, j+1});
        }
    }
}

void calcDistForSher(){
    int i, j;
    pair<int, int> frnt;
    queue<pair<int, int> > que;
    dist4[sher.X][sher.Y] = 0;
    que.push({sher.X, sher.Y});
    bool visited[r+9][c+9];
    memset(visited, false, sizeof visited);
    visited[sher.X][sher.Y] = true;
    while(!que.empty()){
        frnt = que.front(); que.pop();
        i = frnt.X; j = frnt.Y;
        if(i-1 > 0 and
           __map[i-1][j] != 'W' and
           !visited[i-1][j]
          ){
            dist4[i-1][j] = min(dist4[i-1][j], dist4[i][j] + 1);
            visited[i-1][j] = true;
            que.push({i-1, j});
        }
        if(i+1 <= r and
           __map[i+1][j] != 'W' and
           !visited[i+1][j]
          ){
            dist4[i+1][j] = min(dist4[i+1][j], dist4[i][j] + 1);
            visited[i+1][j] = true;
            que.push({i+1, j});
        }
        if(j-1 > 0 and
           __map[i][j-1] != 'W' and
           !visited[i][j-1]
          ){
            dist4[i][j-1] = min(dist4[i][j-1], dist4[i][j] + 1);
            visited[i][j-1] = true;
            que.push({i, j-1});
        }
        if(j+1 <= c and
           __map[i][j+1] != 'W' and
           !visited[i][j+1]
          ){
            dist4[i][j+1] = min(dist4[i][j+1], dist4[i][j] + 1);
            visited[i][j+1] = true;
            que.push({i, j+1});
        }
    }
}

signed main(){
    int i, j, safeGrass=0, totalGrass=0;
    string line;
    cin >> r >> c;
    cin >> g1.X >> g1.Y
        >> g2.X >> g2.Y
        >> g3.X >> g3.Y
        >> sher.X >> sher.Y;
    
    for(i=1; i<=r; ++i){
        cin >> line;
        for(j=1; j<=c; ++j){
            __map[i][j] = line[j-1];
            totalGrass += (__map[i][j] == 'G');
        }
    }
        
    calcDist(g1, dist1);
    calcDist(g2, dist2);
    calcDist(g3, dist3);
    calcDistForSher();
    /*
        *dist1 has minimun dist of any reachable grassland from gate1
        *dist2 has minimun dist of any reachable grassland from gate2
        *dist3 has minimun dist of any reachable grassland from gate3
        *dist4 has minimun dist of any reachable land from Sher
        
    */
    
    for(i=1; i<=r; ++i){
        for(j=1; j<=c; ++j){
            if(
                __map[i][j] == 'G' and(
                dist1[i][j] < dist4[g1.X][g1.Y] or
                dist2[i][j] < dist4[g2.X][g2.Y] or
                dist3[i][j] < dist4[g3.X][g3.Y] or
                dist4[i][j] == INT_MAX)
            ){
                ++safeGrass;
            }
        }
    }
    printf("%.2f", 100.0f * safeGrass / totalGrass);
    return 0;
}
