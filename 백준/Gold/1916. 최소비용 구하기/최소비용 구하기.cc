

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <numeric>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
#define ll long long
using namespace std;

int dist[1003];
int n, m;
vector<ii> adj[1004];

int st, en;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while(pq.size()){
        auto [cost, cur] = pq.top();
        pq.pop();
        
        if(cur == en) break;
        
        for(auto [ncost, nxt]: adj[cur]){
            
            if(dist[nxt] > dist[cur] + ncost){
                dist[nxt] = dist[cur] + ncost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    init
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    fill(dist, dist+ 1003, INF);
    cin >> st >> en;
    
    dijkstra(st);
    cout << dist[en];
}
