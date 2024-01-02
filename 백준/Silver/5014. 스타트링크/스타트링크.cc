#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int f, s, g, u, d;

int visited[2'000'005];

int bfs() {
    queue<int> q;
    q.push(s);
    visited[s] = 0;
    if(s == g) return 0;
    
    while(q.size()) {
        auto here = q.front();
        q.pop();

        for(int nxt: {here - d, here + u}) {
            if(nxt < 1 || nxt > f) continue;
            if(visited[nxt] != -1) continue;

            visited[nxt] = visited[here] + 1;
            q.push(nxt);
            if(nxt == g) {
                return visited[nxt];
            }
        }
    }
    return -1;
}

int main() {
    cin >> f >> s >> g >> u >> d;
    fill(visited, visited+1'000'500, -1);

    int answer = bfs();
    if(answer == -1) cout << "use the stairs";
    else cout << answer;
}
