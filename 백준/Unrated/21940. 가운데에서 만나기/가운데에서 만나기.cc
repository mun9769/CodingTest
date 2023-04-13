#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>

int n, m, k;
int city[202];

int dist[202][202];

#define MAX 987987987

int main() {
  cin >> n >> m;

  for(int i=0; i<202; i++){ 
    fill(dist[i], dist[i] + 202, MAX); 
    dist[i][i] = 0;
  }

  for(int i=0; i<m; i++){
    int a, b, t;
    cin >> a >> b >> t;

    dist[a][b] = t;
  }
  cin >> k;
  for(int i=1; i<=k; i++) cin >> city[i];


  for(int t=1; t<=n; t++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);


  int ret = MAX;
  vector<int> v;

  for(int t=1; t<=n; t++){
    vector<int> pingPongs;
    for(int i=1; i<=k; i++){
      int pingPong = 0;
      if(dist[city[i]][t] == MAX || dist[t][city[i]] == MAX){
        pingPongs.push_back(MAX);
        break;
      }
      pingPong += dist[city[i]][t];
      pingPong += dist[t][city[i]];
      pingPongs.push_back(pingPong);
    }
    sort(pingPongs.begin(), pingPongs.end());

    int mx = *(pingPongs.rbegin());

    if(mx == ret)
      v.push_back(t); 
    else if (mx < ret) {
      v.clear();
      v.push_back(t);
      ret = mx;
    }
  }

  sort(v.begin(), v.end());

  for(auto ele: v)
    cout<< ele << ' ';

}
