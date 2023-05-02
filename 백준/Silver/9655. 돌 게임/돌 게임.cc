#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define ii pair<int, int>


int n;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  if(n % 2 == 1) cout << "SK";
  else cout << "CY";
}
