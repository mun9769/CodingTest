#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9
#define ii pair<int, int>
#define iii tuple<int, int, int>

int n, m;
vector<int> friends[2003];
bool chk[2003];

int ans;

void dfs(int cur, int dep) {
  if(dep >= 5){
    ans = 1;
    return;
  }

  chk[cur] = true;

  for(auto nxt: friends[cur]) {
    if(chk[nxt] == true) continue;
    dfs(nxt, dep+1);
  }

  chk[cur] = false;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }
  for(int i=0; i<=2000; i++){
    if(ans == 1) break;
    if(friends[i].empty()) continue;
    dfs(i, 1);
  }
  cout << ans;
}
