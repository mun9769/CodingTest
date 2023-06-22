//
//  main.cpp
//  cpp
//
//  Created by moon on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <tuple>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9
using namespace std;


int n, m;
int st, en;
int ans;
bool mnFound;

vector<ii> adj[505];
vector<int> prvNode[505];
int dist[505];
bool canGo[505][505];

bool dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    fill(dist, dist + 505, INF);
    dist[st] = 0;
    
    while(pq.size()){
        auto [cost, cur] = pq.top();
        pq.pop();
        
        for(auto [nCost, nxt] : adj[cur]){
            if(canGo[cur][nxt] == false) continue;
            
            if(dist[nxt] > dist[cur] + nCost){
                dist[nxt] = dist[cur] + nCost;
                prvNode[nxt].clear();
                prvNode[nxt].push_back(cur);
                pq.push({dist[nxt], nxt});
            }
            else if(dist[nxt] == dist[cur] + nCost){
                prvNode[nxt].push_back(cur);
            }
            
        }
    }
    return true;
}

void removeTrace(){
    queue<int> q;
    q.push(en);
    bool visited[505];
    fill(visited, visited+505, false);
    visited[en] = true;
    
    while(q.size()){
        auto here = q.front();
        q.pop();
        
        for(auto prv: prvNode[here]){
            canGo[prv][here] = false;
            // cout << prv << ' ' <<here << endl;
            if(visited[prv] == false){
                q.push(prv);
                visited[prv] = true;
            }
        }
    }
}

int main() {
    init
    
    while(true){
        
        for(int i=0; i<505; i++) adj[i].clear();
        for(int i=0; i<505; i++) prvNode[i].clear();
        fill(dist, dist+505, INF);
        mnFound = false;
        
        cin >> n >> m; if(n == 0 && m == 0) break;
        cin >> st >> en;
        
        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
        }
        
        for(int i=0; i<=n; i++) fill(canGo[i], canGo[i]+n+1, true);
        
        dijkstra();
        removeTrace();
        dijkstra();
        
        if(dist[en] == INF) cout << -1 << '\n';
        else cout << dist[en] << '\n';
    }
    
    
}
