#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define INF 987987987

int n, v;
int memo[300]; //무슨 변수?

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> v;
    memo[v + 100]++;
  }
  cin >> v;

  cout << memo[v+100];


}
