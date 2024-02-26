#include <iostream>
#include <queue>
using namespace std;

#define ii pair<int, int> 

int T;
int l;
int a, b;
int x, y;

queue<ii> q;
int table[303][303];

const int dx[] = {-2, -1 ,1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool canGo(int nx, int ny) {
  if(nx < 1 || ny < 1 || nx > l || ny > l) return false;
  if(table[nx][ny] != -1) return false;

  return true;
}

int bfs() {


  while(q.size()){
    int qSize = q.size();

    for(int i=0; i<qSize; i++){
      auto loc = q.front();
      if(loc.first == x && loc.second == y){
        return table[loc.first][loc.second];
      }
      q.pop();

      for(int k=0; k<8; k++){
        int nx = loc.first + dx[k];
        int ny = loc.second + dy[k];

        if(canGo(nx ,ny)){
          q.push({nx, ny});
          table[nx][ny] = table[loc.first][loc.second] + 1;
        }
      }
    }
  }
  return -1;
}


int main() {
  cin >> T;

  while(T--> 0) {
    cin>> l;
    cin >> a >> b;
    cin >> x >> y;
    for(int i=0; i<302; i++){
      fill(table[i], table[i] + 302, -1);
    }
    while(q.size()) q.pop();

    a++;
    b++;
    x++;
    y++;

    table[a][b] = 0;
    q.push({a, b});
    cout << bfs() << '\n';
  }

  return 0;
}