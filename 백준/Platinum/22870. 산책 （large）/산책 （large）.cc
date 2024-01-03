#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define MXN 200'002


int n, m;
vector<ii> adj[MXN];
int st, en;
int dist[MXN];
bool visited[MXN];

void dijkstra(int start) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist+MXN, INT32_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while(pq.size()) {
        auto [acc, cur] = pq.top();
        pq.pop();

        for(auto [cost, nxt]: adj[cur]) {
            if(visited[nxt]) continue;
            if(dist[nxt] > acc + cost) {
                dist[nxt] = acc + cost;
                pq.push({dist[nxt], nxt});
            }
        }


    }
}

auto pred = [](ii& a, ii& b) -> bool {
    return a.second < b.second;
};

void setup(){
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> st >> en;

    for(int i=0; i<MXN; i++) sort(adj[i].begin(), adj[i].end(), pred);
}

int main() {
    setup();

    dijkstra(en);

    int cur = st;
    int acc = 0;

    while(cur != en) {
        for(auto [cost, nxt]: adj[cur]) {
            if(acc + cost == dist[st] - dist[nxt]) {
                acc += cost;
                cur = nxt;
                visited[nxt] = true;
            }
        }
    }
    visited[en] = false;

    dijkstra(st);
    cout << acc + dist[en];

}
