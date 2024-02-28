#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;

int n;
int r, c;
int board[1002][1002];
int arr[1'000'005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int nth = c;
    int ans = 0;

    for(int i=0; i<n; i++) {
        int x = nth / c;
        int y = nth % c;
        if(x > r) break;

        if(board[x-1][y] < arr[i]) {
            board[x][y] = arr[i];
            ans++;
            nth++;
        }
    }

    cout << ans;

    return 0;
}
