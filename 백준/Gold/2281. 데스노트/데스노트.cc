#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1003];
int name[1003];

int n, m;

int main() {
  cin>> n >> m;

  for(int i=0; i<n; i++) {
    cin >> name[i];
  }

  // memset(dp, INT32_MAX, sizeof(dp));
  fill(dp, dp + 1003, INT32_MAX);

  dp[n] = 0;
  int init = 0;
  int i = n-1;

  for(i= n-1; i>=0; i--) {
    init += name[i];
    if(i != n-1) init++;

    if(init > m)
     break;
    dp[i] = 0;
  }

  for(; i>=0; i--) {
    int sum = name[i];
    int remain = m - sum;
    
    dp[i] = remain * remain + dp[i+1];


    for(int j=i+1; j<n; j++){
      sum += name[j];
      sum++;
      if(sum > m) break;

      int remain = m - sum;

      if(dp[i] > remain * remain + dp[j+1]) {
        dp[i] = min(dp[i], remain * remain + dp[j+1]);
      }
    }
  }
  cout<< dp[0];
  

}
