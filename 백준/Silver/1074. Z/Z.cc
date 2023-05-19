#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

#define INF 987654321
int cnt;

int N;
int r, c;
int ans;

void recur(int n, int x, int y){
  if(n == 0){
    cnt++;
    if(x == r and y == c)  ans = cnt;
    return;
  }

  if(x + pow(2, n-1) > r && y + pow(2, n-1) > c) {
    recur(n-1, x, y);
  }
  else {
    cnt += pow(2, n-1) * pow(2, n-1);
  }

  if(x + pow(2, n-1) > r && y + pow(2, n-1) <= c < y + 2 * pow(2, n-1)) {
    recur(n-1, x, y + pow(2, n-1));
  }
  else {
    cnt += pow(2, n-1) * pow(2, n-1);
  }

  if(x + pow(2,n-1) <= r and r < x + 2 * pow(2, n-1) and y + pow(2, n-1) > c) {
    recur(n-1, x + pow(2, n-1), y);
  }
  else {
    cnt += pow(2, n-1) * pow(2, n-1);
  }

  if(x + pow(2,n-1) <= r and r < x + 2 * pow(2, n-1) && y + pow(2,n-1) <= c and c < y + 2*pow(2,n-1)){
    recur(n-1, x + pow(2, n-1), y + pow(2, n-1));
  }
  else{
    cnt += pow(2, n-1) * pow(2, n-1);
  }
}


int main(){

  cin >> N >> r >> c;

  recur(N, 0, 0);

  cout << ans - 1;


}