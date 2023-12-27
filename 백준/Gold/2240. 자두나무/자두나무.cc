#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int t, max_w;
int dp[1002][32][3];
int zadu[1002];

int main() {
    cin >> t >> max_w;
    for(int i=1; i<=t; i++) cin >> zadu[i];

    for(int i=1; i<=t; i++) {
        dp[i][0][1] = dp[i-1][0][1] + (zadu[i] == 1 ? 1 : 0);
        for(int w=1; w<=min(max_w, i); w++) {
            if(zadu[i] == 1) {
                dp[i][w][1] = max(dp[i - 1][w][1], dp[i - 1][w - 1][2]) + 1;
                dp[i][w][2] = max(dp[i - 1][w][2], dp[i - 1][w - 1][1]);
            }
            else {
                dp[i][w][1] = max(dp[i - 1][w][1], dp[i - 1][w - 1][2]);
                dp[i][w][2] = max(dp[i - 1][w][2], dp[i - 1][w - 1][1]) + 1;
            }
        }
    }

    int answer = 0;
    for(int w=0; w<=max_w; w++) {
        int mx = max(dp[t][w][1], dp[t][w][2]);
        answer = max(answer, mx);
    }
    cout << answer;
}
