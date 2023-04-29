#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define ii pair<int, int>


int n;
int a;
priority_queue<int,vector<int>, greater<int>> pq;


int main() {
    cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> a;
      pq.push(a);
      if(pq.size() > n) pq.pop();
    }
  }
  cout << pq.top();

}
