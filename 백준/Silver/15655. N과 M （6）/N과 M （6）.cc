#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
vector<int> target;



void dfs(int idx, int depth){
  if(depth == m){
    for(auto ele : target){ cout << ele << ' '; }
    cout << endl;
    return;
  }

  for(int i=idx; i<n; i++){
    target.push_back(v[i]);
    dfs(i+1, depth+1);
    target.pop_back();
  }
}



int main(){
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    int a; cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  dfs(0, 0);
}