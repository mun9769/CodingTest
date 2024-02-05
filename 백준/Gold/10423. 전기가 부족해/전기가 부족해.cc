#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


int n, m, k;
vector<ii> adj[1004];
int answer;
vector<int> elecCity;
bool visited[1004];

void prim() {
    memset(visited, 0, sizeof(visited));
    priority_queue<ii, vector<ii>, greater<> > pq;
    for(int id: elecCity) {
        pq.push({0, id});
    }
    int cnt = 0;

    while (cnt < n) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;
        cnt++;
        answer += cost;

        for (auto& [ncost, nxt] : adj[cur]) {
            if (!visited[nxt]) {
                pq.push({ ncost, nxt });
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int id;
        cin >> id;
        elecCity.push_back(id);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }
    prim();


    cout << answer;

}
