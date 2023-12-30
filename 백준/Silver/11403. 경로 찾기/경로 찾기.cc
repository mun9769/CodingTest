#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n;
int board[104][104];
int answer[104][104];
bool visited[104];
int st;

void dfs(int cur) {
    if(visited[cur]) return;
    visited[cur] = true;

    for(int i=0; i<n; i++) {
        if(board[cur][i] == 1) {
            answer[st][i] = 1;
            dfs(i);
        }
    }

}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        cin >> board[i][j];
    }

    for(int i=0; i<n; i++) {
        fill(visited, visited+104, false);
        st = i;
        dfs(i);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << endl;
    }
}