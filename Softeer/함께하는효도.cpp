#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n, m;
int board[22][22];
int visited[22][22];
ll sum;
ll ans;

vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};
vector<ii> init;

bool canGo(int nx, int ny) {
    if(nx < 1 || ny < 1 || nx > n || ny > n) return false;
    return true;
}

void dfs(int x, int y, int depth, int id) {
    if(visited[x][y] == 0)
        sum += board[x][y];
    visited[x][y]++;

    if(depth == 3 and id < m - 1) {
        ii& pos = init[id+1];
        dfs(pos.first, pos.second, 0, id+1);
    }
    else if(depth == 3 and id == m-1) {
        ans = max(ans, sum);
    }
    else {
        for (auto &[dx, dy]: offsets) {
            int nx = x + dx;
            int ny = y + dy;
            if (canGo(nx, ny)) {
                dfs(nx, ny, depth + 1, id);
            }
        }
    }

    visited[x][y]--;
    if(visited[x][y] == 0)
        sum -= board[x][y];
}

int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        sum += board[a][b];
        visited[a][b] = 1;
        init.push_back({a, b});
    }
    dfs(init[0].first, init[0].second, 0, 0);
    cout << ans;
    return 0;
}
