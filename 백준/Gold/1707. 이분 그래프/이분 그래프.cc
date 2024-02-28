#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;

int k, v, e;
vector<int> adj[20'005];
int team[20'005];

bool bfs(int st) {
    queue<int> q;
    q.push(st);
    team[st] = 0;

    while(q.size()) {
        auto cur = q.front();
        q.pop();

        for(auto nxt: adj[cur]) {
            if(team[nxt] == -1) {
                team[nxt] = (team[cur] + 1) % 2;
                q.push(nxt);
            }
            else if(team[nxt] == team[cur]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    while(k-- > 0) {
        fill(team, team+20'005, -1);
        cin >> v >> e;
        for(int i=0; i<=20000; i++)
            adj[i].clear();

        for(int i=0; i<e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string ans = "YES";

        for(int i=1; i<=v; i++) {
            bool ret = true;
            if(team[i] == -1) {
                ret = bfs(i);
            }
            if(ret == false) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}
