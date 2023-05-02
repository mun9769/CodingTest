#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define ii pair<int, int>

int a, b, c;


int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
    int i=1;
  while(true){
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0) break;
    int p = c / b;
    int q = c % b;

    q = min(q, a);

    int ans = q + p * a;

    cout << "Case "<<i++ << ": " << ans << '\n';
  }
}
