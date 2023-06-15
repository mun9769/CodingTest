#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define ii pair<int, int>
#define INF 987654321



int ts;
int n;
int projStudent;
int arr[100'005];

int dp[100'005];

int group = 0;

int g[100'005];

void dfs(int here, int cnt){

  if (dp[here] > 0 and g[here] != group){
    return;
  }

  if(arr[here] == here) {
    projStudent++;
    g[here] = ++group;
    dp[here] = 1;
    return;
  }

  if(dp[here] > 0 and g[here] == group){
    projStudent += cnt - dp[here];
    return;
  }


  dp[here] = cnt;
  g[here] = group;

  dfs(arr[here], cnt + 1);
}

int main(){
  cin.tie(0) ->ios_base::sync_with_stdio(0);

  cin >> ts;
  while(ts-->0){
    fill(dp,dp+100'005, 0);
    fill(g, g+100'005, 0); 
    fill(arr, arr+100'005, 0);

    projStudent = 0;

    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];

    for(int i=1; i<=n; i++){
      if(dp[i] == 0) {
        group++;
        dfs(i, 1);
      }
    }

    cout << n - projStudent << endl;
  }
}