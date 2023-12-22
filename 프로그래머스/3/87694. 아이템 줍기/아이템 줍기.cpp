#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int board[105][105];
// 0 : null
// 1 : possible
// -1: impossible
int visited[105][105];

int itemX;
int itemY;

void draw_path(int left, int right, int bottom, int top) {
    
    for(int i=left+1; i<right; i++){
        for(int j=bottom+1; j<top; j++){
            board[i][j] = -1;
        }
    }
    for(int i=left; i<=right; i++) {
        if(board[i][bottom] != -1) board[i][bottom] = 1;
        if(board[i][top] != -1) board[i][top] = 1;
    }
    for(int j=bottom; j<=top; j++) {
        if(board[left][j] != -1)  board[left][j] = 1;
        if(board[right][j] != -1)  board[right][j] = 1;
    }
    
}

bool canGo(int nx, int ny) {
    if(nx < 0 || ny < 0 || nx > 101 || ny > 101) return false;
    if(board[nx][ny] != 1) return false;
    if(visited[nx][ny] >= 0) return false;
    
    return true;
}

int bfs(int u, int v) {
    queue<ii> q;
    q.push({u, v});
    visited[u][v] = 0;
    vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(auto offset: offsets) {
            int nx = x + offset.first;
            int ny = y + offset.second;
            
            if(canGo(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                if(nx == itemX and ny == itemY) {
                    return visited[nx][ny];
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int _itemX, int _itemY) {
    int answer = 0;
    itemX = _itemX*2;
    itemY = _itemY*2;
    memset(visited, -1, sizeof(visited));
    
    for(auto rec: rectangle) {
        draw_path(rec[0]*2,rec[2]*2,rec[1]*2,rec[3]*2);
    }
    
    answer = bfs(characterX*2, characterY*2) / 2;
    
    return answer;
}