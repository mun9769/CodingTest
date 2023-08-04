#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int G, P;
int arr[100'005];

int p[100'005];
int ans = 0;

int _find(int x) {
  if(p[x] == x) return x;
  return p[x] = _find(p[x]);
}

int _select(int g){
  int par = _find(g);

  if(par == 0) return 0;

  p[par] = p[par-1];
  ans++;
  return 1;

}

int main() {
  cin.tie(0) -> ios_base::sync_with_stdio(false);
  cin >> G >> P;
  for(int i=0; i<P; i++) cin >> arr[i];

  for(int i=1; i<=max(G, P); i++){ p[i] = i; }

  for(int i=0; i<min(G,P); i++){
    int ret = _select(arr[i]);
    if(ret == 0) break;
  }
  cout << ans;

}