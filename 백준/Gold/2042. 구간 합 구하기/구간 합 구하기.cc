#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long


int n, m, k;
ll arr[1'000'008];
ll BIT[1'000'008];


ll add(int i) {
  ll ret = 0;
  while(i) {
    ret += BIT[i];
    i -= (i & -i);
  }
  return ret;
}

void update(int i, ll val){
  while(i <= n) {
    BIT[i] += val;
    i += (i & -i);
  }
}
void update(int i, ll val, ll sub) {
  while(i <= n) {
    BIT[i] -= sub;
    BIT[i] += val;
    i += (i & -i);
  }
}

int main() {
  cin >> n >> m >> k;
  for(int i=1; i<=n; i++) cin >> arr[i];

  for(int i=1; i<=n; i++){
    update(i, arr[i]);
  }

  ll a, b, c;
  for(int i=1; i<=(m + k); i++){
    cin >> a >> b >> c;
    switch(a){
      case 1:
        update(b, c, arr[b]);
        arr[b] = c;
      break;
      case 2:
        cout << add(c) - add(b-1) << '\n';
      break;
      default: 
        cout <<"a has wrong" <<'\n';
      break;
    }
  }
}
