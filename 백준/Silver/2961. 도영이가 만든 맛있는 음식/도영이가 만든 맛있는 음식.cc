#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9
#define ii pair<int, int>
#define iii tuple<int, int, int>

int n;
vector<ii> ingredients;
int ans = INF;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    ingredients.push_back({a, b});
  }

  for(int i=1; i < (1 << n); i++ ){
    vector<int> ret;
    for(int j=0; j<n; j++){
      if(i & (1 << j)) ret.push_back(j);
    }

    int left = 1;
    int right = 0;

    for(int x: ret) {
      ii ingredient = ingredients[x];
      left *= ingredient.first;
      right += ingredient.second;
    }

    ans = min(ans, abs(left - right));

  }
  cout << ans;


}
