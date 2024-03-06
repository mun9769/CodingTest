#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int inf = INT32_MAX;


int n, k;
int t[500'005];
int visited[500'005][2];

void bfs() {
    for(int i=0; i<500'005; i++){
        visited[i][0] = inf;
        visited[i][1] = inf;
    }

    queue<int> q;
    q.push(n);
    visited[n][0] = 0;
    int cnt = 0;

    while(q.size()) {
        cnt++;
        int qSize = q.size();
        for(int z=0; z<qSize; z++) {
            auto cur = q.front();
            q.pop();

            for(int nxt: {cur-1, cur+1, cur*2}) {
                if(nxt > 500'000 || nxt < 0)
                    continue;

                if(visited[nxt][cnt % 2] <= cnt)
                    continue;

                visited[nxt][cnt % 2] = cnt;
                q.push(nxt);
            }
        }
    }

}

int main() {
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }

    bfs();
    int ans = INT32_MAX;

    for(int i=0; i<500'000 and k <= 500'000; i++) {
        k += i;
        if(k > 500'000)
            break;
        if(i % 2 == 0) {
            if(visited[k][0] <= i) {
                ans = min(ans, i);
            }
        }
        else {
            if(visited[k][1] <= i) {
                ans = min(ans, i);
            }
        }
    }
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}
