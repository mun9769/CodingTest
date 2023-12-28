#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n, m;

int board[130][130];
vector<iii> adj[130][130];
int dist[130][130];

int accumulate() {
    for(int i=1; i<n; i++) { // 상단
        for(int j=0; j<i+1; j++) {

            int x = i - j + 1;
            int y = j + 1;

            int top = board[x-1][y];
            int lft = board[x][y-1];

            board[x][y] += min(top, lft);
        }
    }

    for(int i=n; i<2*n-1; i++) {
        for(int j=n-1; j>=1; j--) {

            int y = i - j + 1;
            int x = j + 1;

            int top = board[x-1][y];
            int lft = board[x][y-1];

            board[x][y] += min(top, lft);
        }
    }

    return board[n][n];
}

void make_adjacent() {
    vector<ii> offsets = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, };

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {

        for(ii offset: offsets) {
            int nx = i + offset.first;
            int ny = j + offset.second;
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            adj[i][j].push_back({board[nx][ny], nx, ny});
        }
    }
}

int dijkstra() {
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({board[1][1], 1, 1});
    dist[1][1] = board[1][1];

    while(pq.size()) {
        auto [acc, x, y] = pq.top();
        pq.pop();
        if(x == n and y == n) return acc;

        for(auto [cost, nx, ny]: adj[x][y]) {
            if(dist[nx][ny] > acc + cost) {
                dist[nx][ny] = acc + cost;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }

    throw std::logic_error("도착지에 도착하지 못했습니다");
}

void init() {
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
            cin >> board[i][j];
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
            adj[i][j].clear();
            dist[i][j] = inf;
    }
    make_adjacent();
}

int main() {
    int test_case = 1;
    while(cin >> n) {
        if(n == 0) break;

        init();
        cout << "Problem " << test_case++ << ": " << dijkstra() << '\n';
    }
}
