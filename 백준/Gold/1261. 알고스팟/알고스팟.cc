#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long
#define iii tuple<int, int, int>


int n, m;

int table[200][200];
int dp[200][200];
bool chk[200][200];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool canGo(int nx, int ny){
  if(nx < 1 || ny < 1 || nx > n || ny > m) return false;
  if(chk[nx][ny]) return false;

  return true;
}

void dijktra() {
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  pq.push({0, 1, 1});
  chk[1][1] = true;

  while(pq.size()){
    auto [c,x,y] = pq.top(); pq.pop();
    // cout << x << ' ' << y << endl;

    if(x == n && y == m) {
      cout << c;
      break;
    }

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(canGo(nx, ny)){
        chk[nx][ny] = true;

        int cost = table[nx][ny] ? dp[x][y] + 1 : dp[x][y];

        dp[nx][ny] = cost;

        pq.push({cost, nx, ny});
      }
    }

  }

}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  cin >> m >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<m; j++){
      if(s[j] == '0') table[i+1][j+1] = 0;
      else table[i+1][j+1] = 1;
    }
  }

  dijktra();

}
