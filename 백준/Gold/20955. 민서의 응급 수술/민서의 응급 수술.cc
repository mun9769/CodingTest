#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


int n, m;
int u, v;
vector<int> adj[100'004];
bool visited[100'004];
int answer;
int edge;
int vertex;


void dfs(int cur) {
    visited[cur] = true;
    edge += adj[cur].size();
    vertex += 1;

    for(int x: adj[cur]) {
        if(visited[x] == false) {
            dfs(x);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++ ){
        if(visited[i] == false) {
            edge = 0;
            vertex = 0;
            dfs(i);

            edge = edge / 2;
            answer += edge - vertex + 1;
            answer++;
        }
    }
    cout << answer - 1;
}
