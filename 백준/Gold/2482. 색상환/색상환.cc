#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int> 
#define iii tuple<int, int, int>

int mod = 1'000'000'003;


int line[1003][1003];


int main() {
  int n, k;
  cin >> n >> k;

  for(int i=0; i<=n; i++){
    line[i][0] = 1;
  }

  for(int i=1; i<= n; i++){
    line[i][1] = i;
  }

  for(int j=2; j<=n; j++){
      for(int i=j+1; i<=n; i++){
      line[i][j] = (line[i-1][j] + line[i-2][j-1]) % mod;
    }
  }

  int a = line[n-3][k-1] % mod;
  int b = line[n-1][k] % mod;

  cout<< (a + b) % mod;


}