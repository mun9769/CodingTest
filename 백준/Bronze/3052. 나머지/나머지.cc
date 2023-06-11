#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
#define ii pair<int, int>
#define INF 987654321


int cnt[55];


int main(){
  for(int i=0; i<10; i++){
    int a; 
    cin >> a;
    cnt[a % 42]++;
  }
  int ans = 0;
  for(int i=0; i<44; i++){
    if(cnt[i]) ans++;
  }
  cout << ans;
}