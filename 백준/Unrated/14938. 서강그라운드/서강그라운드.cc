#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>

int n, m, r;

int items[103];

bool chk[103];
int D[103][103];

int sum;
int ans;


int main() {
  cin>> n >> m >> r;

  for(int i=1; i<=n; i++) cin >> items[i];

  for(int i=0; i<=101; i++) fill(D[i], D[i] + 103, 987654321);

  for(int i=1; i<=n; i++) D[i][i] = 0;

  for(int i=1; i<=r; i++){
    int a, b, c;
    cin >> a >> b >> c;
    D[a][b] = c;
    D[b][a] = c;
  }  

  // 플로이드
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);


  for(int i=1; i<=n; i++) {
    int sum = 0;
    for(int j=1; j<=n; j++){
      if(D[i][j] <= m) sum += items[j];
    }

    ans = max(ans, sum);

  }
  cout<< ans;
}
