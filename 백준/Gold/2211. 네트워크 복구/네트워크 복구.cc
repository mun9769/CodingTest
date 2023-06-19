#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define INF 987654321

int n, m;
vector<ii> adj[1002];
int dist[1002];
int p[1002];
vector<ii> v;

void prim(){
  priority_queue<ii, vector<ii>, greater<ii>> pq; 

  pq.push({0, 1});
  dist[1] = 0;

  while(pq.size()){
    auto [d, cur] = pq.top();
    pq.pop();

    for(auto [cost, nxt]: adj[cur]){

      if(dist[nxt] > d + cost){
        dist[nxt] = d + cost;
        p[nxt] = cur;
        pq.push({d + cost, nxt});
      }
    }
  }

}

int main(){
  init
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  fill(dist, dist+1002, INF);
  prim();

  cout << n-1 << '\n';
  for(int i=2; i<=n; i++){
    cout << p[i] << ' ' << i << '\n';
  }
}