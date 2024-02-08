#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int board[22][22];

int cnt[51][405];

int n, m;
vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};

void bfs(int i, int j) {
    int visited[22][22];
    memset(visited, 0, sizeof visited);
    queue<ii> q;
    q.push({ i, j });
    visited[i][j] = 1;

    int gid = n * i + j;
    int dist = 1;
    int hCount = 0;

    while (q.size()) {
        int qSize = q.size();
        while (qSize-- > 0) {
            auto [x, y] = q.front();
            q.pop();

            if(board[x][y] == 1)
                hCount++;

            for (auto [dx, dy] : offsets) {
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        cnt[dist][gid] = hCount;
        dist++;
    }
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int ans = 0;
        memset(board, 0, sizeof board);
        memset(cnt, 0, sizeof cnt);
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                bfs(i, j);
            }
        }

        for(int k=1; k<=51; k++) {
            int cost = k * k + (k-1)*(k-1);
            bool allzero = true;
            for(int id=0; id<n*n; id++) {
                if(cnt[k][id] != 0) {allzero = false; break;}
            }
            if(allzero) break;

            for (int id = 0; id < n * n; id++) {
                int& home = cnt[k][id];
                int plus = home * m;
                if(plus - cost >= 0 and ans < home) {
                    ans = home;
                }
            }
        }
        cout << '#'<<tc<<' ' << ans << '\n';
    }


    return 0;
}
