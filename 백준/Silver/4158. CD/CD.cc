#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
#include <unordered_set>

using namespace std;
#define ii pair<int, int>
#define INF 987654321

int n, m;


int main(){
  cin.tie(0) ->ios_base::sync_with_stdio(0);
  while(true){
    cin >> n >> m;
    if(n == 0 and m == 0) break;
    int ans = 0;

    unordered_set<int> us;
    for(int i=0; i<n; i++){
      int a; cin >> a;
      us.insert(a);
    }
    for(int i=0; i<m; i++){
      int a; cin >> a;
      if(us.count(a)) ans++;
    }
    cout << ans << ' ';


  }
}