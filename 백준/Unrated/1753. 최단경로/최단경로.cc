#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define INF 987987987


int v, e;
int k;

vector<vector<ii>> graph(20'003);
int dist[20'003];


void dij() {
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, k});

  while(pq.size()){
    auto [now, here] = pq.top(); 
    pq.pop();

    if(dist[here] > now) continue;

    for(auto [cost, there] : graph[here]){
      int nc = dist[here] + cost;

      if(dist[there] > nc){
        dist[there] = nc;
        pq.push({nc, there});
      }
    }

  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> v >> e;
  cin >> k;

  fill(dist, dist+ 20'003, INF);
  dist[k] = 0;

  for(int i=0; i<e; i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    graph[a].push_back({cost, b});
  }

  dij();
  for(int i=1; i<=v; i++){
    if(dist[i] == INF) cout <<"INF\n";
    else cout << dist[i] << '\n';
  }

}
