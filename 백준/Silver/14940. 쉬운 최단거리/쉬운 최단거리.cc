#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n, m;
int board[1003][1003];
bool visited[1003][1003];
ii st;
vector<ii> offsets = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, };

void bfs() {
    queue<ii> q;
    q.push(st);
    board[st.first][st.second] = 0;
    visited[st.first][st.second] = true;

    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for(ii offset: offsets) {
            int nx = x + offset.first;
            int ny = y + offset.second;

            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(board[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;


            board[nx][ny] += board[x][y];
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
        cin >> board[i][j];
        if(board[i][j] == 2) st = {i, j};
    }

    bfs();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(board[i][j] == 1) {
                int dist = abs(i-st.first) + abs(j-st.second);
                if(dist == 1) cout << board[i][j] << ' ';
                else cout << -1 << ' ';
            }
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
