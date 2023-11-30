#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int land[504][505];
bool visited[505][505];
int n, m;

const int dx[] = {1, 0 ,-1, 0};
const int dy[] = {0 ,-1, 0 ,1};

int mn, mx;
int store[505];

bool canGo(int nx, int ny) {
    if(nx < 1 || ny < 1 || nx > n || ny > m) return false;
    if(land[nx][ny] == 0) return false;
    if(visited[nx][ny]) return false;
    return true;
}


int drill(int x, int y){
    if(canGo(x, y) == false) return 0;
    visited[x][y] = true;
    mn = min(mn, y);
    mx = max(mx, y);
    
    int sum = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += drill(nx, ny);
    }
    
    return sum + 1;
}

int ans;

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
    	for(int j=1; j<=m; j++) {
            mn = j;
            mx = j;
            int oils = drill(i, j);
            
            for(int k = mn; k<=mx; k++) store[k] += oils;
        }
    }
    
    for(int i=1; i<=m; i++)
        answer = max(answer, store[i]);
    
    
    return answer;
}