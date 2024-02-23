#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int n, m;
vector<int> adj[1004];
bool vis[1004];
stack<int> s;

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;

    for(int i=1; i<=n; i++) {
        if(vis[i] == false) {
            s.push(i);
            ans++;
            vis[i] = true;
        }

        while(s.size()) {
            int cur = s.top();
            s.pop();

            for(auto nxt: adj[cur]) {
                if(vis[nxt] == false) {
                    vis[nxt] = true;
                    s.push(nxt);
                }
            }
        }

    }
    cout << ans;


}
