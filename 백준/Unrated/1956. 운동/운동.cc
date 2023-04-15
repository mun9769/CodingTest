#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>

#define INF 987987987

int dist[404][404];
int v, e;

int main() {
  cin >> v >> e;

  for(int i=1; i<=402; i++){
    fill(dist[i], dist[i] + 402, INF);
    dist[i][i] = 0;
  }

  for(int i=1; i<=e; i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    dist[a][b] = cost;
  }

  for(int k=1; k<=v; k++)
    for(int i=1; i<=v; i++)
      for(int j=1; j<=v; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int ans = INF;

  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      if(i == j) continue;
      if(dist[i][j] == INF || dist[j][i] == INF) continue;
      int sum = dist[i][j] + dist[j][i];

      ans = min(ans, sum);
    }
  }

  if(ans != INF) cout<< ans;
  else cout << -1;
}
