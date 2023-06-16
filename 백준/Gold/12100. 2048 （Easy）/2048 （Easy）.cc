#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
#define ii pair<int, int>
#define INF 987654321

int n;
int ans;
vector<vector<int>> board;

// 0 UP
// 1 DOWN
// 2 LEFT
// 3 RIGHT

void move(vector<vector<int>>& b, int dir) {
  // RIGHT
  if(dir == 3) for(int i=0; i<n; i++){
    int idx = n-1;
    for(int j=n-1; j>=0; j--){
      if(idx == j) continue;
      else if(b[i][j] == 0) continue;
      else if(b[i][idx] == b[i][j]) { // 옮길 곳과 값이 같다면
        b[i][idx] = b[i][idx] << 1;
        b[i][j] = 0;
        idx--;
        continue;
      }
      else if(b[i][idx] == 0){ // 옮길 곳과 값이 다르다면
        b[i][idx] = b[i][j];
        b[i][j] = 0;
      }
      else if(b[i][idx] != b[i][j]){
        idx--;
        if(idx == j) continue;
        b[i][idx] = b[i][j];
        b[i][j] = 0;
      }
    }
  }
  // UP
  if(dir == 0) {
    for(int j=0; j<n; j++){
      int idx = 0;
      for(int i=0; i<n; i++){
        if(idx == i) continue;
        else if(b[i][j] == 0) continue;
        else if(b[idx][j] == b[i][j]) {
          b[idx][j] = b[idx][j] << 1;
          b[i][j] = 0;
          idx++;
        }
        else if(b[idx][j] == 0){
          b[idx][j] = b[i][j];
          b[i][j] = 0;
        }
        else if(b[idx][j] != b[i][j]){
          idx++;
          if(idx == i) continue;
          b[idx][j] = b[i][j];
          b[i][j] = 0;
        }
      }
    }
  }
  // DOWN
  if(dir == 1) {
    for(int j=0; j<n; j++){
      int idx = n-1;
      for(int i=n-1; i>=0; i--){
        if(idx == i) continue;
        else if(b[i][j] == 0) continue;
        else if(b[idx][j] == b[i][j]) {
          b[idx][j] = b[idx][j] << 1;
          b[i][j] = 0;
          idx--;
        }
        else if(b[idx][j] == 0){
          b[idx][j] = b[i][j];
          b[i][j] = 0;
        }
        else if(b[idx][j] != b[i][j]){
          idx--;
          if(idx == i) continue;
          b[idx][j] = b[i][j];
          b[i][j] = 0;
        }
      }
    }
  }
  // LEFT
  if(dir == 2) for(int i=0; i<n; i++){
    int idx = 0;
    for(int j=0; j<n; j++){
      if(idx == j) {continue;}
      else if(b[i][j] == 0) continue;
      else if(b[i][idx] == b[i][j]) { // 옮길 곳과 값이 같다면
        b[i][idx] = b[i][idx] << 1;
        b[i][j] = 0;
        idx++;
        continue;
      }
      else if(b[i][idx] == 0){ 
        b[i][idx] = b[i][j];
        b[i][j] = 0;
      }
      else if(b[i][idx] != b[i][j]) { // 옮길 곳과 값이 다르다면
        idx++;
        if(idx == j) continue;
        b[i][idx] = b[i][j];
        b[i][j] = 0;
      }
    }
  }
}

void dfs(vector<vector<int>> state, int cnt) {
  if(cnt == 5){
    int mx = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        mx = max(mx, state[i][j]);
      }
    }
    ans = max(ans, mx);
    return;
  }

  for(int i=0; i<4; i++){
    vector<vector<int>> b = state;
    move(b, i);
    dfs(b, cnt+1);
  }
}


int main(){
  cin.tie(0) ->ios_base::sync_with_stdio(0);
  cin >> n;

  board.resize(n);

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) 
      {
        int a; cin >> a;
        board[i].push_back(a);
      }

  dfs(board, 0);

  cout << ans;

}