#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long


int n;
ll arr[5005];
ll ans[3];
ll sz = 3'000'000'001;

int main(){
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;

  for(int i=1; i<=n; i++){ cin >> arr[i]; }
  sort(arr+1, arr+n+1);

  for(int i=1; i<=n-2; i++){

    int l = i+1;
    int r = n;

    while(l < r){
      ll val = arr[i] + arr[l] + arr[r];

      if(sz > abs(val)){
        sz = abs(val);
        ans[0] = arr[i]; ans[1] = arr[l]; ans[2] = arr[r];
      }
      if(val < 0) l++;
      else r--;
    }
  }

  sort(ans, ans+3);
  for(int i=0; i<3; i++) cout << ans[i] << ' ';
}