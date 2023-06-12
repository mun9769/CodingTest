#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ii pair<int, int>
#define INF 987654321

int v;
vector<ii> adj[100'005];

vector<ii> ch[100'005];

bool chk[100'005];
int ans;

void getTree(int here){
  chk[here] = true;
  for(auto [c, there]: adj[here]){
    if(chk[there]) continue;

    ch[here].push_back({c, there});
    getTree(there);
  }
}

int dfs(int here){
  if(ch[here].size() == 0) return 0;

  chk[here] = true;

  vector<int> v;

  for(auto [c, there] : ch[here]){
    if(chk[there]) continue;

    int k = dfs(there) + c;
    v.push_back(k);
  }
  sort(v.begin(), v.end(), greater<int>());

  if(v.size() >= 2) { ans = max(ans, v[0]+v[1]); }
  else { ans = max(ans, v[0]); }

  return v[0];
  
}

int main(){
  cin >> v;
  for(int i=0; i<v; i++){
    int a; cin >> a;

    int b, c;
    while(true){
      cin >> b; if(b == -1) break;
      cin >> c;
      adj[a].push_back({c,b});
    }
  }
  getTree(1);

  fill(chk, chk+100'005, false);

  dfs(1);

  cout << ans; 
}