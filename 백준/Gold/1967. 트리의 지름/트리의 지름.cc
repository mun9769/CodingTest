#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long
#define iii tuple<int, int, int>

int n;
int a, b, c;
vector<ii> child[10'004];
int ans;

int getCost(int here){
  vector<int> v;

  int mn = 0;
  int sum = 0;

  for(auto [there, cost] : child[here]){
    int d = getCost(there) + cost;
    v.push_back(d);
  }

  sort(v.rbegin(), v.rend());

  for(int i=0; i<v.size(); i++){
    if(i>=2) break;
    mn = max(mn, v[i]);
    sum += v[i];
  }

  ans = max(ans, sum);

  return mn;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;

  for(int i=0; i<n-1; i++){
    cin >> a >> b >> c;
    child[a].push_back({b, c});
  }
  getCost(1);

  cout << ans;

}
