#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;


int visited[103][103];
queue<ii> q;

vector<string> maps;
ii start_point;
int n, m;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool canGo(int nx, int ny){
    if(nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
    if(visited[nx][ny] != -1) return false;
    if(maps[nx][ny] == 'X') return false;
    
    return true;
}

enum Destination {
    LEVER, EXIT
};

int bfs(Destination d) {
    for(int i=0; i<102; i++) fill(visited[i], visited[i] + 102, -1); 
    q = queue<ii>();
    q.push(start_point);
    auto [u, v] = start_point;
    visited[u][v] = 0;
    
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(canGo(nx, ny)){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                if(d == Destination::LEVER and maps[nx][ny] == 'L') {
                    start_point = {nx, ny};
                    return visited[nx][ny];
                }
                if(d == Destination::EXIT and maps[nx][ny] == 'E')
                    return visited[nx][ny];
            }
        }
    }
    return -1;
}

int solution(vector<string> _maps) {
    int answer = 0;
    maps = _maps;
    n = maps.size();
    m = maps[0].size();
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] == 'S') start_point = {i, j}; 
        }
    }
    
    int result_1 = bfs(Destination::LEVER);
    if(result_1 == -1) return -1;
    else  answer += result_1;
    
    
    int result_2 = bfs(Destination::EXIT);
    if(result_2 == -1) return -1;
    else answer += result_2;
    
    
    return answer;
}