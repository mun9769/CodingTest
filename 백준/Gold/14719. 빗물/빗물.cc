#include <iostream>
#include <vector>
using namespace std;

int h, w;
int building[503];

int main() {
  cin >> h >> w;
  for(int i=1; i<=w; i++){ cin >> building[i]; }
  int ans = 0;

  for(int i=2; i<=w - 1; i++) {

    int left = i - 1;
    int right = i + 1;
    int lh = 0;
    int rh = 0;
    while(left > 0) {
      lh = max(lh, building[left]);
      left--;
    }
    while(right <= w) {
      rh = max(rh, building[right]);
      right++;
    }
    int ch = building[i];

    if(lh <= ch or rh <= ch) continue;

    ans += min(lh, rh) - ch;
    
  }
  cout << ans;
  

}