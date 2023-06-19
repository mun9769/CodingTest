#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define INF 987654321

int n;
int arr[1'000'005];
int dp[1'000'005];
vector<int> v;

int main(){
  init
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];

  v.push_back(arr[0]);
  dp[0] = 0;

  for(int i=1; i<n; i++){
    auto iter = lower_bound(v.begin(), v.end(), arr[i]);

    if(iter == v.end()){
      v.push_back(arr[i]);
      dp[i] = v.size()-1;
    }
    else {
      *iter = arr[i];
      dp[i] = iter - v.begin();
    }
  }

  cout << v.size() << '\n';

  int idx = v.size()-1;
  vector<int> ans;

  for(int i=n-1; i>=0; i--){
    if(dp[i] == idx){
      ans.push_back(arr[i]);
      idx--;
    }
  }
  for(int i=v.size()-1; i>=0; i--){
    cout << ans[i] << ' ';
  }



}