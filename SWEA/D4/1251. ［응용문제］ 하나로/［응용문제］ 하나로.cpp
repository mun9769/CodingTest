#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
int n;
double e;
ll dist[1002][1002];
pll pos[1002];

ll dist_two_point(pll& a, pll& b) {
    return pow(a.first - b.first, 2) +
           pow(a.second - b.second, 2);
}

ll prim() {
    ll answer = 0;
    bool visited[1002];
    fill(visited, visited+1002, false);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({0, 1}); // 비용, 정점
    int cnt = 0;

    while(pq.size() and cnt < n) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if(visited[cur]) continue;

        visited[cur] = true;
        cnt++;

        answer += cost;

        for(int i=1; i<=n; i++) {
            if (cur == i) continue;
            if (visited[i]) continue;

            pq.push({dist[cur][i], i});
        }
    }
    return answer;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> pos[i].first;
        for(int i=1; i<=n; i++)
            cin >> pos[i].second;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                ll distance = dist_two_point(pos[i], pos[j]);
                dist[i][j] = distance;
                dist[j][i] = distance;
            }
        }
        cin >> e;
        ll answer = round(e * prim());

        cout <<'#'<<tc<<' ';
        cout << answer << '\n';


    }
}