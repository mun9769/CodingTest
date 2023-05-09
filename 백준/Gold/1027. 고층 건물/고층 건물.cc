#include <iostream>
#include <string>

using namespace std;

double arr[55];
int n;

int main() {
  cin.tie(0) -> ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=1; i<=n; i++) cin >> arr[i];

  int ans = 0;
  for(int cur = 1; cur<=n; cur++){
    int cnt = 0;
    for(int i=1; i<=n; i++){
      if(i == cur) continue;

      double slope = double(arr[i] - arr[cur]) / double(i - cur);
      bool possible = true;

      if(i > cur) {
        for(int j = cur + 1; j < i; j++){
          double h = slope * double(j - cur); 

          h += arr[cur];


          if(h <= arr[j]) {
            possible = false;
            break;
          }
        }
      }
      else {
        for(int j = i + 1; j < cur; j++){
          double h = slope * double(j - i);
          h += arr[i];
          if(h <= arr[j]) {
            possible = false;
            break;
          }
        }
      }

      if(possible) cnt++;

    }
    ans = max(ans, cnt);
  }
  cout << ans;
}
