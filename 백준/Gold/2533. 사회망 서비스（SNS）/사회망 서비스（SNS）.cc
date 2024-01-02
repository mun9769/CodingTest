#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


vector<int> adj[1'000'004];
vector<int> chd[1'000'004];
int dp[1'000'004][2];
int n;

void mktree(int cur, int prv) {
    for(auto nxt: adj[cur]) {
        if(nxt == prv) continue;
        chd[cur].push_back(nxt);
        mktree(nxt, cur);
    }
}

int dfs(int cur, bool is_adapter) {
    if(dp[cur][is_adapter] != -1)
        return dp[cur][is_adapter];

    int result = 0;
    if(is_adapter) {
        for(auto nxt: chd[cur]) {
            result += min(dfs(nxt, true), dfs(nxt, false));
        }
        result++;
    }
    else {
        for(auto nxt: chd[cur]) {
            result += dfs(nxt, true);
        }
    }

    return dp[cur][is_adapter] = result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<1'000'004; i++) { fill(dp[i], dp[i]+2, -1); }
    mktree(1, -1);

    cout << min(dfs(1, true), dfs(1, false));


}
