#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define ii pair<int, int>

int n;
int a, b;
priority_queue<int> pq;
vector<vector<int>> v(200'002);


int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    v[a].push_back(b);
  }
  int ans = 0;

  for(int today = n; today >=1; today--){
    for(auto ele : v[today])
      pq.push(ele);



    if(pq.size()){
      ans += pq.top();
      pq.pop();
    }
  }
  std::cout << ans;

}
