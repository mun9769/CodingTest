#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9
#define ii pair<int, int>
#define iii tuple<int, int, int>

vector<int> emp[55];
int n;

int dfs(int cur) {

  if(emp[cur].empty()) return 0;

  int ret = 0;
  vector<int> v;

  for(auto x : emp[cur]) {
    int k = dfs(x);
    v.push_back(k);
  }

  sort(v.begin(), v.end(), greater<int>());

  for(int i=0; i<v.size(); i++){
    ret = max(ret, v[i] + i + 1);
  }

  return ret;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  int p;
  cin >> p;

  for(int i=1; i<n; i++){
    cin >> p;
    emp[p].push_back(i);
  }
  
  cout << dfs(0);
}
