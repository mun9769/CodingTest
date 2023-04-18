#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

set<int> chk;


int n, q;
int query;
int region;
int dist;
int loc = 1;


int main() {
  cin.tie(0) -> ios::sync_with_stdio(0);


  cin >> n >> q;

  for(int i=1; i<=n; i++){
    int a; cin >> a;
    if(a == 1){ chk.insert(i); }
  }

  for(int i=0; i<q; i++){
    cin >> query;

    switch(query) {
      case 1:
        cin >> region;
        if(chk.count(region)){ chk.erase(region); }
        else { chk.insert(region); }
        break;

      case 2:
        cin >> dist;
        loc = (loc + dist - 1) % n + 1;
        break;

      case 3:
        if(chk.empty()) { cout << -1 << '\n'; break;}

        int res = -2;

        auto iter = chk.lower_bound(loc);

        if(iter != chk.end()) { res = *iter - loc; }
        else { res = *chk.begin() + n - loc; }

        cout << res << '\n';
        break;
    }
  }

}
