#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n;

int board[130][130];
int dist[130][130];

int dijkstra() {
    vector<ii> offsets = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, };
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({board[1][1], 1, 1});
    dist[1][1] = board[1][1];

    while(pq.size()) {
        auto [acc, x, y] = pq.top();
        pq.pop();
        if(x == n and y == n) return acc;

        for(ii offset: offsets) {
            int nx = x + offset.first;
            int ny = y + offset.second;
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            int cost = board[nx][ny];

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
            dist[i][j] = inf;
    }
}

int main() {
    int test_case = 1;
    while(cin >> n) {
        if(n == 0) break;

        init();
        cout << "Problem " << test_case++ << ": " << dijkstra() << '\n';
    }
}
