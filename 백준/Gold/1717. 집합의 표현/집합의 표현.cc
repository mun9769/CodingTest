#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

int par[1'000'004];

int n, m, a, b;
int op;


int Find(int x){
  if(par[x] == x) return x;
  else return par[x] = Find(par[x]);
}

bool Union(int x, int y){
  x = Find(x);
  y = Find(y);
  if(x == y){
     return false;
  }

  par[x] = y;
  return true;
}


int main() {
  cin.tie(0) -> ios_base::sync_with_stdio(0);
  
  cin >> n >> m;

  for(int i=0; i<=n; i++) par[i] = i;


  for(int i=0; i<m; i++){
    cin >> op >> a >> b;
    if(op == 0){ Union(a, b); }
    else {
      if(Find(a) == Find(b)) cout << "yes\n";
      else cout << "no\n";
    }
  }

}