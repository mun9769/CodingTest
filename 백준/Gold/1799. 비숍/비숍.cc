#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;
int board[12][12];
vector<ii> lst[30];
bool visited[30];
int answer;

void dfs(int cur, int cnt) {
    if(cur == 2 * n - 1) {
        answer = max(answer, cnt);
        return;
    }
    if(answer >= cnt + 2 * n -1 - cur) { // 남은 자리 다 놓아도 정답일 수 없는 경우를 가지치기한다.
        return;
    }

    for(auto [i, j]: lst[cur]) {
        if(visited[i-j] == false) {
            visited[i-j] = true;
            dfs(cur+1, cnt + 1);
            visited[i-j] = false;
        }
    }
    dfs(cur+1, cnt);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        cin >> board[i][j];

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(board[i][j] == 1)
            lst[i+j].push_back({i, j});
    }

    dfs(0, 0);

    cout << answer;

}
