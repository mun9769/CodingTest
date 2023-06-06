#include <iostream>
#include <vector>
using namespace std;

int n;
bool board[20][20];
int ans;


bool chk(int x, int y){
  for(int i=1; i<=n; i++){
    if(board[x][i]) return false;
  }
  for(int i=1; i<=n; i++){
    if(board[i][y]) return false;
  }
  for(int i=1; i<=n; i++){
    if(x+i > n || y+i > n) break;
    if(board[x+i][y+i]) return false;
  }
  for(int i=1; i<=n; i++){
    if(x-i < 1 || y-i < 1) break;
    if(board[x-i][y-i]) return false;
  }
  for(int i=1; i<=n; i++){
    if(x+i > n || y-i < 1) break;
    if(board[x+i][y-i]) return false;
  }
  for(int i=1; i<=n; i++){
    if(x-i < 1 || y+i > n) break;
    if(board[x-i][y+i]) return false;
  }
  return true;
}

void dfs(int target){
  if(target == n + 1) {ans++; return;}

  for(int i=1; i<=n; i++){
    if(chk(target, i)) {

      board[target][i] = true;
      dfs(target+1);
      board[target][i] = false;
    }
  }

  
}

int main(){
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;

  dfs(1);
  cout << ans;
}