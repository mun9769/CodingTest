#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

vector<int> adj[500'005];
vector<int> ch[500'005];
int n;
ll tTurn;

void mktree(int cur, int prv) {
    for (int nxt: adj[cur]) {
        if (nxt != prv) {
            ch[cur].push_back(nxt);
            mktree(nxt, cur);
        }
    }
}

void dfs(int cur, int depth) {

    for (int nxt : ch[cur]) {
        dfs(nxt, depth + 1);
    }

    if (ch[cur].empty()) {
        tTurn += depth;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mktree(1,0);
    dfs(1, 0);
    if (tTurn % 2 == 1)
        cout << "Yes";
    else
        cout << "No";


}
