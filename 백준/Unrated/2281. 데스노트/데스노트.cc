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
  
  /*
  for(int i=0; i<n; i++){
    cout<< dp[i] << ' ';
  }
  */
  cout<< dp[0];
  

}

/*

int table[1003][1003];
int name[1003];
int remains[1003][1003];

int n, m;

int main() {
  cin >> n >> m;

  for(int i=1; i<=n; i++) cin >> name[i];

  for(int i=0; i<1003; i++) fill(table[i], table[i] + 1002, INT32_MAX); 

  int lineSum = 0;

  for(int y= 1; y < 1003; y++){

    lineSum += name[y];
    if(y != 1) lineSum++;

    int remain = m - lineSum;
    if(remain < 0) break;

    table[1][y] = remain * remain;


  }

  for(int x=2; x <= n; x++){
    for(int prev=x; table[x-1][prev-1] != INT32_MAX; prev++){

      int sum = 0;

      for(int y= prev; y <= n; y++){

        sum += name[y];
        if(y != prev) sum++;

        int remain = m - sum;
        if(remain < 0) break;



        if(table[x][y] >= table[x-1][prev-1] + remain * remain) {
          table[x][y] = table[x-1][prev-1] + remain * remain;

          remains[x][y] = remain * remain;
        }

      }
    }
  }


  int ans = INT32_MAX;
  for(int i=1; i<=n; i++){
    if(ans > table[i][n]) {
      ans = table[i][n];
      ans -= remains[i][n];
    }
  }
  cout<< ans;

}
*/ 

