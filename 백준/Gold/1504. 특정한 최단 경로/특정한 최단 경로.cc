#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
#define ii pair<int, int>
#define INF 987654321


int n,e;
int v1, v2;
vector<ii> adj[808];
int dist[808];

int dij(int st, int en){
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, st});
  fill(dist, dist+808, INF);
  dist[st] = 0;

  while(pq.size()){
    auto [c, here] = pq.top(); 
    pq.pop();

    if(here == en) return dist[here];

    for(auto [cost, there] : adj[here]){
      if(dist[there] > dist[here] + cost){
        dist[there] = dist[here] + cost;
        pq.push({dist[there], there});
      }

    }

  }

  return INF;

}

int main(){
  std::cin.tie(0) -> ios_base::sync_with_stdio(0);
  std::cin >> n >> e;
  for(int i=0; i<e; i++){
    int a, b, c;
    std::cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  std::cin >> v1 >> v2;

  if(v1 > v2) swap(v1, v2);

  long long ans1 = 0;
  ans1 += dij(1, v1);
  ans1 += dij(v1, v2);
  ans1 += dij(v2, n);

  long long ans2 = 0;
  ans2 += dij(1, v2);
  ans2 += dij(v2, v1);
  ans2 += dij(v1, n);

  long long ans = min(ans1, ans2);

  if(ans >= INF) cout << -1;
  else cout << ans;

}