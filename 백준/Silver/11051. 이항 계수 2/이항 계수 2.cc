

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <numeric>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
#define ll long long
using namespace std;


int ts;
int N, K;
#define mod 10007

int ans;
int dp[1002][1002];

int dfs(int n, int k){
    
    if(n == k) return dp[n][k] = 1;
    if(k == 0) return dp[n][k] = 1;
    if(k == 1) return dp[n][k] = n;
    if(dp[n][k] > 0) return dp[n][k];
    
    
    return dp[n][k] = dfs(n-1, k) % mod  + dfs(n-1, k-1) % mod;
}

int main() {
    init
    cin >> N >> K;
    cout << dfs(N, K) % mod;
    
}
