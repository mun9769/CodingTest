#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define INF 987987987

int n, r, q;
int num; 

vector<int> childs[100'005];
int cnt[100'005];
bool chk[100'005];

int makeTree(int here){

  chk[here] = true;

  int sum = 1;

  for(auto child: childs[here]){
    if(chk[child]) continue;

    sum += makeTree(child);
  }

  cnt[here] = sum;

  return sum;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> r >> q;
  for(int i=0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    childs[b].push_back(a);
    childs[a].push_back(b);
  }

  makeTree(r);

  for(int i=0; i<q; i++){
    cin >> num;
    cout<< cnt[num] << '\n';
  }
}
