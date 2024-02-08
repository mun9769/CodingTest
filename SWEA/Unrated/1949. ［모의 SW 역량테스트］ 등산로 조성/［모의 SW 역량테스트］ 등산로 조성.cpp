#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int board[10][10];
int n, k;

vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};


int visited[10][10];
int ans = 0;

void dfs(int x, int y, int dep, bool check) {

    visited[x][y] = 1;
    if(ans < dep) {
        ans = dep;
    }

    for(auto [dx, dy]: offsets) {
        int nx = x + dx;
        int ny = y + dy;

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(visited[nx][ny]) continue;

        if(board[nx][ny] < board[x][y]) {
            dfs(nx, ny, dep+1, check);
        }
        else if(check == false and board[nx][ny] - k < board[x][y]) {
            int tmp = board[nx][ny];
            board[nx][ny] = board[x][y] - 1;
            dfs(nx, ny, dep+1, true);
            board[nx][ny] = tmp;
        }
    }
    visited[x][y] = 0;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int mx = 0;
        ans = 0;
        cin >> n >> k;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> board[i][j];
                mx = max(mx, board[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(mx == board[i][j]) {
                    memset(visited, 0, sizeof visited);
                    dfs(i, j, 1, false);
                }
            }
        }
        cout << '#'<<tc<<' '<< ans << '\n';

    }


    return 0;
}
