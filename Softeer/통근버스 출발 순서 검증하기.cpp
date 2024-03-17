#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int n;
int arr[5005];

int main(int argc, char** argv)
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=n; j>i; j--) {
            if(arr[i] > arr[j]) {
                cnt++;
            }
            dp[i][j] = cnt;
        }
    }
    long long ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(arr[j] < arr[i]) {
                ans += dp[j][i+1];
            }
        }
    }
    cout << ans;

   return 0;
}
