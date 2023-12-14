#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

vector<string> board;

int visited[102][102];

queue<ii> q;

const int dx[] = {0, 1, 0, -1}; // e, s, w, n
const int dy[] = {1, 0, -1, 0};

bool canGo(ii there) {
    auto [x, y] = there;
    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
    if(board[x][y] == 'D') return false;
    
    return true;
}


ii next_block(ii cur, int dir) {
    ii ret = cur;
    
    ret.first  += dx[dir];
    ret.second += dy[dir];
    
    while(canGo(ret)) {
        ret.first  += dx[dir];
        ret.second += dy[dir];
    }
    
    ret.first  -= dx[dir];
    ret.second -= dy[dir];
    
    auto [nx, ny] = ret;
    if(visited[nx][ny] > -1) return cur;
    
    return ret;
}



int bfs() {
    while(q.size()) {
        auto cur = q.front();
        auto [x, y] = cur;
        q.pop();

        for(int i=0; i<4; i++){
            ii nxt = next_block(cur, i);

            if(nxt != cur) {
                auto [nx, ny] = nxt;
                visited[nx][ny] = visited[x][y] + 1;
                if(board[nx][ny] == 'G') return visited[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<string> _board) {
    int answer = 0;
    board = _board;
    int n = board.size();
    int m = board[0].size();
    for(int i=0; i<102; i++)
        fill(visited[i], visited[i]+102, -1);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m;j++) if(board[i][j] == 'R') {
            q.push({i, j});
            board[i][j] = '.';
            visited[i][j] = 0;
        }
    
    
    answer = bfs();
    
    
    return answer;
}