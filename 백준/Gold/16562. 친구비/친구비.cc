#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


int n, m, k;
int payment[10'005];
vector<int> adj[10'005];
bool visited[10'005];
int answer;

int dfs(int cur) {
    visited[cur] = true;

    int result = payment[cur];

    for(int x: adj[cur]){
        if(visited[x] == false) {
            result = min(result, dfs(x));
        }
    }

    return result;
}


int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> payment[i];

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(a == b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            answer += dfs(i);
        }
    }
    if(answer > k) cout << "Oh no";
    else cout << answer;
}
