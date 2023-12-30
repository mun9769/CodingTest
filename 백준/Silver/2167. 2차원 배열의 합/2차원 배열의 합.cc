#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n, m, k;
int p, q, x, y;
int board[303][303];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int u=1; u<=n; u++) for(int v=1; v<=m; v++) {
        cin >> board[u][v];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
        }
    }

    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> p >> q >> x >> y;
        cout << board[x][y] - board[x][q-1] - board[p-1][y] + board[p-1][q-1] << '\n';
    }



}