#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

int v, e;
ll p, q, s;
vector<tuple<ll,ll,ll>> line;

int parent[10'004];
int ans;

int cnt;

int find(int x){
  if(parent[x] == x) return x;
  else return parent[x] = find(parent[x]);
}

bool _union(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;

  parent[min(x, y)] = max(x, y);
  return true;
}

int main() {
  cin.tie(0) -> ios::sync_with_stdio(0);
  cin >> v >> e;

  for(int i=0; i<=v; i++) parent[i] = i;

  for(int i=0;i <e; i++){
    cin >> p >> q >> s;
    line.push_back({s, p, q});
  }

  sort(line.begin(), line.end());

  for(auto [c, a, b] : line){
    if(_union(a, b)){
      ans += c;
      cnt++;

      if(cnt == v - 1) break;
    }
  }
  cout << ans;


  


}
