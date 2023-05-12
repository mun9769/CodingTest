#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long

int T;
int n, k, w;
int D[1004];

vector<int> adj[1004];

int cnt[1005];

int cost[1004];


void bfs(){
  queue<int> q;
  for(int i=1; i<=n; i++)
    if(!cnt[i]) q.push(i);
  
  while(q.size()){

    auto here = q.front(); q.pop();

    for(auto there : adj[here]){
      cnt[there]--;

      int c = cost[here] + D[there];
      if(cost[there] < c) {
        cost[there] = c;
      }
      if(cnt[there] == 0){
        q.push(there);
        if(there == w) return;
      }
    }


  }
}


int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);

  cin >> T;
  while(T-->0){
    cin >> n >> k;
    fill(cnt, cnt+1004, 0);

    for(int i=0; i<=n; i++) adj[i].clear();
    for(int i=1; i<=n; i++) {cin >> D[i]; cost[i] = D[i]; }
    for(int i=1; i<=k; i++){
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      cnt[b]++;
    }

    cin >> w;

    bfs();


    
    cout<< cost[w] << '\n';




  }
}
