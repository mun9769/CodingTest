#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
int arr[2][3];
int ans;
int cnt;

void dfs(int cur, int dep, int work, int sum) {
    if(dep == n) {
        if(sum >= m)
            ans++;
        return;
    }
    cnt++;

    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            int w = arr[i][j];
            if(cur == j) w /= 2;

            dfs(j, dep+1, i, sum + w);
        }
    }

}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            dfs(j, 1, i, arr[i][j]);
        }
    }

    cout << ans;


    return 0;
}
