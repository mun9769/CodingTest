#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n, m;

int board[505][505];

vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};

bool visited[505][505];

bool can_go(int nx, int ny) {
    if(nx < 0 || ny < 0 || nx > n || ny > m) return false;
    if(visited[nx][ny]) return false;

    return true;
}
int answer;

void dfs(int x, int y, int depth, int sum) {
    if(depth == 3) {
        answer = max(answer, sum);
        return;
    }

    visited[x][y] = true;

    for(auto offset: offsets) {
        int nx = x + offset.first;
        int ny = y + offset.second;

        if(can_go(nx, ny)) {
            dfs(nx, ny, depth+1, sum + board[nx][ny]);
        }
    }

    visited[x][y] = false;
}


void find_woo() {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == 1 and j == 1) continue;
            if(i == 1 and j == m) continue;
            if(i == n and j == 1) continue;
            if(i == n and j == m) continue;

            int sum = board[i][j];
            for(auto offset: offsets) {
                int nx = i + offset.first;
                int ny = j + offset.second;
                sum += board[nx][ny];
            }
            for(auto offset: offsets) {
                int nx = i + offset.first;
                int ny = j + offset.second;
                answer = max(answer, sum - board[nx][ny]);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dfs(i, j, 0, board[i][j]);
        }
    }
    find_woo();



    cout << answer;



}
