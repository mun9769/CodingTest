#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define INF 987654321


int a, b;

int main(){
  cin >> a >> b;
  int c = gcd(a, b);
  cout << c << ' ' << a*b/c;
}