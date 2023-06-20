#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 987654321


int n, m;
vector<iii> edges;
long long dist[505];

bool bellman_ford(){
  dist[1] = 0;
  
  for(int i=1; i<=n+1; i++){
    for(auto edge: edges){
      auto [st, en, cost] = edge;

      if(dist[st] == INF) continue;
      if(dist[en] > dist[st] + cost){
        dist[en] = dist[st] + cost;
        if(i == n+1) return false;
      }
    }
  }
  return true;
}


int main(){
  init
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }
  fill(dist, dist+505, INF);

  if(bellman_ford() == false) cout << -1;
  else{
    for(int i=2; i<=n; i++){
      if(dist[i] == INF) cout << -1 << '\n';
      else cout << dist[i] << '\n';
    }
  }
}