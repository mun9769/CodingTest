#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

#define INF 1'987654321
#define ii pair<int, int>

int segMx[300'004];
int segMn[300'004];
int n, m;
int arr[100'004];


ii getVal(int idx, int st, int en, int l, int r) {

  if(r < st || en < l) return {0,INF};

  if(l <= st and en <= r) return {segMx[idx], segMn[idx]};

  auto left = getVal(idx*2, st, (st+en)/2, l, r);
  auto right = getVal(idx*2+1, (st+en)/2 + 1, en, l, r);

  return {max(left.first, right.first), min(left.second, right.second)};
}

void update(int idx, int st, int en, int i){
  segMx[idx] = max(segMx[idx], arr[i]);
  segMn[idx] = min(segMn[idx], arr[i]);

  if(st == en) return;

  if(i <= (st+en)/2) update(2*idx, st, (st+en)/2, i);
  else update(2*idx+1, (st+en)/2 + 1, en, i);
}

int main(){
  cin.tie(0) -> ios_base::sync_with_stdio(0);
  fill(segMn, segMn+300'004, INF);

  cin >> n >> m;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    update(1, 1, n, i);
  }

  for(int i=1; i<=m; i++){
    int a, b;
    cin >> a >> b;
    auto [mx, mn] = getVal(1, 1, n, a, b);
    cout << mn << ' ' << mx << '\n';
  }

}