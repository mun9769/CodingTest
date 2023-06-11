#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
#define ii pair<int, int>
#define INF 987654321


int cnt[30];

string s;

int l2U(char c){
  if('a' <= c and c <= 'z'){
    return c - 'a';
  }
  return c - 'A';
}

int main(){
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> s;
  for(char c: s){
    int al = l2U(c);
    cnt[al]++;
  }
  vector<int> v;
  int mx = 0;
  for(int i=0; i<28; i++){
    mx = max(mx, cnt[i]);
  }
  for(int i=0; i<28; i++){
    if(mx == cnt[i]) v.push_back(i);
  }
  if(v.size() > 1) cout << "?";
  else if(v.size() == 1){
    char k = v[0] + 'A';
    cout << k;
  }
}