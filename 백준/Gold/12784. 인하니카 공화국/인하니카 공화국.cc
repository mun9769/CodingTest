#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 2'200'003

int t, n, m;
vector<ii> adj[1002];
vector<ii> chd[1002];

void setup() {
    cin.tie(0) ->sync_with_stdio(0);
    cin >> t;
}

void mktree(int cur, int prv) {
    for(auto [cost, nxt] : adj[cur]) {
        if(nxt == prv) continue;
        chd[cur].push_back({cost, nxt});
        mktree(nxt, cur);
    }
}

void dfs(int cur, int& parent) {
    if(chd[cur].empty())
        return;

    int sum = 0;
    for(auto& [cost, nxt]: chd[cur]) {
        dfs(nxt, cost);
        sum += cost;
    }

    if(parent > sum)
        parent = sum;
}

int main() {

    setup();
    while(t-- > 0) {
        for(int i=0; i<1001; i++)
            adj[i].clear(), chd[i].clear();

        cin >> n >> m;
        for(int i=0; i<n-1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        mktree(1, -1);
        int answer = INT32_MAX;
        dfs(1, answer);
        if(answer == INT32_MAX) cout << 0 << '\n';
        else cout << answer << '\n';
    }

}
