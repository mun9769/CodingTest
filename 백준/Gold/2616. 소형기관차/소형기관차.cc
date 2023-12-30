#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n, k;
int arr[50'005];
int dp[4][50'005];
int mx[3][50'005];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> k;

    int sum = 0;
    for(int i=0; i<k-1; i++) { sum += arr[i]; }

    for(int i=0; i<=n-k; i++) {
        sum += arr[i+k-1];
        dp[1][i] = sum;
        sum -= arr[i];
    }
    int mt = 0;
    for(int i=0; i<n; i++) {
        mt = max(mt, dp[1][i]);
        mx[1][i] = mt;
    }

    for(int i=k; i<=n-k; i++) {
        dp[2][i] = dp[1][i] + mx[1][i-k];
    }

    mt = 0;
    for(int i=0; i<n; i++) {
        mt = max(mt, dp[2][i]);
        mx[2][i] = mt;
    }

    for(int i=2*k; i<=n-k; i++) {
        dp[3][i] = dp[1][i] + mx[2][i-k];
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[3][i]);
    }
    cout << answer;
}