#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9
#define INFll 1e18

int n, m, w;
vector<iii> edges;
long long dist[505];
int ts;

bool bellman_ford(){
  dist[1] = 0;

  for(int i=1; i<n; i++){
    for(auto edge: edges){
      auto [st, en, cost] = edge;

      if(dist[en] > dist[st] + cost){
        dist[en] = dist[st] + cost;
      }
    }
  }

    for(auto edge: edges){
      auto [st, en, cost] = edge;

      if(dist[en] > dist[st] + cost){
        return false;
      }
    }
  return true;
}


int main(){
  init;
  cin >> ts;
  while(ts-->0){
    cin >> n >> m >> w;
    fill(dist, dist+505, INFll);
    edges.clear();

    for(int i=0; i<m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      edges.push_back({a, b, c});
      edges.push_back({b, a, c});
    }

    for(int i=0; i<w; i++){
      int a, b, c;
      cin >> a >> b >> c;
      edges.push_back({a, b, -c});
    }

    if(bellman_ford() == false) cout << "YES\n";
    else{ cout << "NO\n"; }
  }
}

