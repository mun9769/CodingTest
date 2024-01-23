#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
int n;
char c;
int board[104][104];
int dist[104][104];
vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};

int dijkstra() {
    for(int i=0; i<=n+1; i++)
        fill(dist[i], dist[i]+104, inf);
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push({0, 1, 1});
    dist[1][1] = 0;

    while(pq.size()) {
        auto [acc, x, y] = pq.top();
        pq.pop();

        for(auto offset: offsets) {
            int nx = x + offset.first;
            int ny = y + offset.second;
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            int cost = dist[x][y] + board[nx][ny];

            if(dist[nx][ny] > cost) {
                dist[nx][ny] = cost;
                pq.push({cost, nx, ny});

                if(nx == n and ny == n)
                    return cost;
            }
        }
    }

    throw logic_error("도달하지 못함");
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
//    freopen("sample_input.txt", "r", stdin);

    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        cin >> n;

        for(int i=0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c;
                board[i + 1][j + 1] = c - '0';
            }
        }

        cout << '#'<<tc<<' ';
        cout << dijkstra() << '\n';
    }



    return 0;
}