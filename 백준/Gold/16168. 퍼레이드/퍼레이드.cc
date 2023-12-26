#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int v, e;
vector<int> adj[3003];
bool visited[3003];

void dfs(int cur) {
    visited[cur] = true;
    
    for(auto x: adj[cur]) {
        if(visited[x] == false) {
            dfs(x);
        }
    }
}

int main() {
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    bool all_visited = all_of(visited+1, visited+1+v, [](bool x) { return x == true; });
    if(all_visited == false) {
        cout << "NO"; return 0;
    }

    int even = 0;
    int odd = 0;

    for(int i=1; i<=v; i++) {
        if(adj[i].size() % 2 == 0) even++;
        else odd++;
    }

    if(odd == 2 or even == v) cout << "YES";
    else cout << "NO";

}
