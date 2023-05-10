#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ii pair<int, int>
#define INF 987654321


int h, m;

int main() {
  cin >> h >> m;

  if(m < 45) {
    h -= 1;
    if(h<0) h = 23;
    m += 15;
  }
  else {
    m -= 45;
  }

  cout << h << ' '<< m;

}
