#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int inf = 9876;

int n, p, k;
vector<ii> adj[1006];

int ans = -1;
int dp[1006];

bool dijkstra(int x) {
    fill(dp, dp+1006, inf);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dp[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [num, cur] = pq.top();
        pq.pop();

        if(dp[cur] != num)
            continue;

        for(auto [cost, nxt]: adj[cur]) {

            int nnum = num + (cost > x);
            if(dp[nxt] > nnum) {
                dp[nxt] = nnum;
                pq.push({nnum, nxt});
            }
        }
    }
    return dp[n] <= k;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample_input.txt", "r", stdin);
    cin >> n >> p >> k;

    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    int l = -1, r = 1'000'000;

    while(l + 1 < r) {
        int mid = (l+r) / 2;

        bool possible = dijkstra(mid);

        if(possible) {
            r = mid;
            ans = mid;
        }
        else {
            l = mid;
        }
    }

    cout << ans;
}
