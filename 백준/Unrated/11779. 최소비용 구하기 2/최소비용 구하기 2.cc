#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define INF 987987987

int n, m;
int from, to; // 해설은 무슨변수?

vector<vector<ii>> adj(1'003);
int dist[1'004];
int prv[1'004]; // 해설은 무슨변수?

vector<int> v;
int cnt = 1;

void dij() {
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, from});
  dist[from] = 0;

  while(pq.size()){
    auto [d, here] = pq.top();
    pq.pop();
    if(here == to) break;

    for(auto [cost, there] : adj[here]){
      int nd = d + cost;

      if(dist[there] > nd){
        dist[there] = nd;
        pq.push({nd, there});
        prv[there] = here;

      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost, b});
  }
  cin >> from >> to;

  fill(dist, dist + 1004, INF);

  dij();

  cout<< dist[to]<< '\n';
  for(int i=to; i != from; i = prv[i]){
    cnt++;
    v.push_back(i);
  }
  cout<< cnt<< '\n';

  cout<< from << ' ';
  for(auto iter = v.rbegin(); iter != v.rend(); iter++){
    cout<< *iter<< ' ';
  }


}
