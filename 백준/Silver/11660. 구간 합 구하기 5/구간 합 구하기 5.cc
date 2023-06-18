#include <iostream>
#include <vector>

using namespace std;
#define ii pair<int, int>
#define INF 987654321

int n, m;
int board[1100][1100];
int dp[1100][1100];

int main(){
  cin.tie(0) ->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      cin >> board[i][j];

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + board[i][j];
    }
  }
  for(int i=1; i<=m; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int sum = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
    cout << sum << '\n';
  }


}