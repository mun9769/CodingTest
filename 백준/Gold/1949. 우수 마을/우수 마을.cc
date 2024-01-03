#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define MXN 10'003


int n;
vector<int> adj[MXN];
vector<int> chd[MXN];
int dp[MXN][2];
int village[MXN];
bool only_chd[MXN];
bool leaf[MXN];
bool has_leaf[MXN];

bool mktree(int cur, int prv) {
    int cnt = 0;
    bool has_leaf_node = false;
    for(auto nxt: adj[cur]) {
        if(nxt == prv) continue;
        cnt++;
        chd[cur].push_back(nxt);
        has_leaf_node |= mktree(nxt, cur);
    }
    if(cnt == 0) { leaf[MXN] = true; return true; }
    if(cnt == 1) { only_chd[MXN] = true; }

    if(has_leaf_node) has_leaf[cur] = true;
    return false;
}

int dfs(int cur, bool parent) {
    if(dp[cur][parent] != -1)
        return dp[cur][parent];

    int val1 = 0;
    for(int nxt: chd[cur]) {
        val1 += dfs(nxt, false);
    }

    int val2 = -1;
    if(parent == false) {
        val2 = village[cur];
        for(int nxt: chd[cur])
            val2 += dfs(nxt, true);
    }

    return dp[cur][parent] = max(val1, val2);
}

void setup() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> village[i];
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mktree(1, -1);

    for(int i=0; i<10'003; i++) fill(dp[i], dp[i] + 2, -1);
}

int main() {
    setup();
    cout << dfs(1, false);

}
