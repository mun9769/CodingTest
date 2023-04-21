#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;


int n, m;
int a, b;
vector<int> adj[600];
bool chk[600];
int ans;
queue<int> q;

void bfs() {
  q.push(1);
  chk[1] = true;
  int k = 3;

  while(k-- > 0){
    int qSize = q.size();
    for(int i=0; i<qSize; i++){

      int here = q.front(); q.pop();
      ans++;

      for(auto there: adj[here]){
        if(chk[there] == false){
          chk[there] = true;
          q.push(there);
        }
      }
    }
    
  }


}



int main() {
  cin.tie(0) -> ios::sync_with_stdio(0);

  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs();


  cout << ans - 1 << '\n';


  

}
