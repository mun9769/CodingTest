#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define init cin.tie(0)->sync_with_stdio(0)


#define INF 2e9

int n;
int score[200'006];
int dp[4][200'005];

int ans;

int main() {
  init;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> score[i];
  }

  dp[0][0] = score[0];
  dp[1][0] = score[0] * 2;
  dp[2][0] = -INF;
  dp[3][0] = -INF;


  for(int i=1; i<n; i++) {
    int a = dp[0][i-1];
    int b = dp[3][i-1];

    dp[0][i] = max(a,b) + score[i];
    dp[1][i] = max(a,b) + score[i] * 2;
    dp[2][i] = dp[1][i-1] + score[i] * 2;
    dp[3][i] = dp[2][i-1] + score[i] * 2;
  }

  int ans = -INF;
  for(int i=0; i<4; i++) {
    ans = max(ans, dp[i][n-1]);
  }
  cout << ans;
}