#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int land[504][505];
bool visited[505][505];
int n, m;

int oilId = 1;
const int dx[] = {1, 0 ,-1, 0};
const int dy[] = {0 ,-1, 0 ,1};

ii oil[505][505];

bool canGo(int nx, int ny) {
    if(nx < 1 || ny < 1 || nx > n || ny > m) return false;
    if(land[nx][ny] == 0) return false;
    if(visited[nx][ny]) return false;
    return true;
}

void bfs(int u, int v) {
    if(visited[u][v]) return;
    if(land[u][v] == 0) return;
    
    queue<ii> q;
    q.push({u, v});
    visited[u][v] = true;
    vector<ii> location;
    
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        location.push_back({x, y});
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(canGo(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    int store = location.size();
    for(auto [x, y]: location) {
        oil[x][y] = {oilId, store};
    }
    oilId++;
    
}
int ans;

void drill() {
    for(int j=1; j<=m; j++){
        vector<int> drilledOil;
        int sum = 0;
        
        for(int i=1; i<=n; i++){
            int id = oil[i][j].first;
            int store = oil[i][j].second;
            
            if(find(drilledOil.begin(), drilledOil.end(), id) == drilledOil.end()) {
                sum += store;
                drilledOil.push_back(id);
            }
        }
        ans = max(ans, sum);
        
    }
}

int solution(vector<vector<int>> _land) {
    int answer = 0;
    n = _land.size();
    m = _land[0].size();
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++) {
        	land[i+1][j+1] = _land[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            bfs(i, j);
        }
    }
    drill();
    answer = ans;
    
    return answer;
}