#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define init cin.tie(0)->sync_with_stdio(0)


int n;
vector<int> v;
bool chk[1005];

int main() {
  init;
  cin >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  int prv = -1;
  int cnt = 0;
  for(int i=0; i<v.size(); i++) {
    if(prv < v[i]) {
      // cout << v[i] << ' ';
      chk[i] = true;
      prv = v[i];
      cnt++;
    }
  }
  // cout << endl;

  int ans = cnt;
  prv = -1;
  cnt = 0;
  for(int i=0; i<v.size(); i++) {
    if(prv < v[i] && chk[i] == false) {
      // cout << v[i] << ' ';
      prv = v[i];
      cnt++;
    }
  }
  ans += cnt;
  cout << ans;

}