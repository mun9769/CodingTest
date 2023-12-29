#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n, m;
int st, en;
vector<ii> adj[5005];
int dist[5005];

int dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    dist[st] = 0;

    while(pq.size()) {
        auto [acc, cur] = pq.top();
        pq.pop();
        if(cur == en) break;

        for(auto [cost, nxt]: adj[cur]) {
            if(dist[nxt] > acc + cost) {
                dist[nxt] = acc + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    return dist[en];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> st >> en;
    fill(dist, dist+5005, inf);

    cout << dijkstra();
}
