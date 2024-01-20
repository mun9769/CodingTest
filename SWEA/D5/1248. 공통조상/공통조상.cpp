#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 10'004

int v, e, a, b;
int T;
int p[Mxn];
bool visited[Mxn];
vector<int> chd[Mxn];
int subtree_sz;

void setup() {
    cin >> v >> e >> a >> b;
    subtree_sz = 0;
    for(int i=0; i<Mxn; i++) chd[i].clear();
    fill(visited, visited+10'004, false);
    fill(p, p+10'004, -1);

    for(int i=0; i<e; i++) {
        int parent, child;
        cin >> parent >> child;
        p[child] = parent;
        chd[parent].push_back(child);
    }
}

void dfs(int cur) {
    subtree_sz++;

    for(auto nxt: chd[cur])
        dfs(nxt);
}

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    cin >> T;
    p[1] = -1;

    for(int test_case = 1; test_case <= T; test_case++) {
        setup();

        while(a != -1)
            visited[a] = true, a = p[a];

        while(!visited[b])
            b = p[b];

        dfs(b);

        cout <<'#'<<test_case<<' ' << b << ' ' << subtree_sz<<'\n';

    }

    return 0;

}
