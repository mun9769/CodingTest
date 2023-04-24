#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;

#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>

vector<long long> _numbers;

ll numPow(int n) {
  ll ret = 0;
  while(n > 1){
    ret++;
    n = n / 2;
  }
  return ret;
}

vector<ll> tenToTwo(ll n){
  vector<ll> s;
  while(n > 1){
    s.push_back(n % 2);
    n = n / 2;
  }
  s.push_back(n);
  return s;
}

void sizeFit(vector<ll>& v){ // 음...
  int vSize = v.size();
  if(vSize == 1) return;

  int cnt = numPow(vSize); // 형변환 잘 되겠지?
  cnt++;

  int t = pow(2, cnt) - 1 - vSize;

  for(int i=0; i < t; i++){
    v.push_back(0);
  }

}

bool bfs(vector<ll>& v) {
  queue<int> q;
  int mid = v.size() / 2;
  q.push(mid);
  int cnt = v.size() + 1;
  int k = numPow(cnt);

  k = pow(2, k - 2);

  while(q.size()){
    int qSize = q.size();
    if(k == 0) break;
    for(int i=0; i<qSize; i++){
      int here = q.front();
      q.pop();

      for(auto there : {here - k, here + k}){
        q.push(there);
        if(v[here] == 0 && v[there] == 1) 
          return false;
      }
    }
    k = k / 2;
  }
  return true;

}



vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto num : numbers){
      vector<ll> bin = tenToTwo(num);
      sizeFit(bin);

      if(bfs(bin)) answer.push_back(1);
      else answer.push_back(0);

    }
    return answer;
}

int main() {
  for(auto a : solution({5})){
    cout << a;
  }
}
