#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n, k;

int weight[1'002];
int score[1'002];

int dp[1004][10'002];

int dfs(int i, int remainder) {
    if(i < 1)
        return 0;
    if(dp[i][remainder])
        return dp[i][remainder];

    int result = 0;

    int lft = 0;
    int rht = 0;

    lft = dfs(i-1, remainder);
    if(remainder >= weight[i])
        rht = dfs(i-1, remainder - weight[i]) + score[i];

    result = max(lft, rht);

    return dp[i][remainder] = result;
}

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1; i<=k; i++) {
        cin >> score[i] >> weight[i];
    }

    cout << dfs(k, n);


}
