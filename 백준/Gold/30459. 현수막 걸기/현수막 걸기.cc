#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define init cin.tie(0)->sync_with_stdio(0)


int n, m;
double R;
double tree[2005];
double flag[40'005];



int main() {
  init;

  cin >> n >> m >> R;
  for(int i=0; i<n; i++) {
    cin >> tree[i];
  }
  for(int i=0; i<m; i++){
    cin >> flag[i];
  }
  sort(tree, tree + n);
  sort(flag, flag + m);


  double ans = -1;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      double width = tree[j] - tree[i];

      int l = 0, r = m-1;
      double semiArea = -1;

      while(l <= r) {
        int mid = (l + r) / 2;

        double height = flag[mid];

        double area = width * height / 2;

        if(area > R) {
          r = mid-1;
        }
        else if(semiArea <= area) {
          l = mid+1;
          semiArea = area;
        }
        else {
          r = mid-1;
        }
      }
      
      ans = max(ans, semiArea);

    }
  }

  if(ans == -1) cout << -1;
  else cout << std::fixed << std::setprecision(1) << ans;

}