#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n, m;
int dist[202];
int storage[202];
vector<ii> adj[202];

void dijkstra(int start) {
    fill(dist, dist+202, inf);
    fill(storage, storage+202, inf);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    storage[start] = 0;

    while(pq.size()) {
        auto [acc, cur] = pq.top();
        pq.pop();

        for(auto [cost, nxt]: adj[cur]) {
            if(dist[nxt] > acc + cost) {
                dist[nxt] = dist[cur] + cost;
                pq.push({dist[nxt], nxt});

                if(cur == start) storage[nxt] = nxt;
                else storage[nxt] = storage[cur];
            }
        }
    }
}

void print_storage() {
    for(int i=1; i<=n; i++){
        if(storage[i] == 0) cout << "- ";
        else cout << storage[i] << ' ';
    }
    cout << '\n';
}

void solution(int start) {
    dijkstra(start);
    print_storage();
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    for(int i=1; i<=n; i++)
        solution(i);
}
