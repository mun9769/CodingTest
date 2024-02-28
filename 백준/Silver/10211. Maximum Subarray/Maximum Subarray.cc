#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;

int n;
int T;
int arr[1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while(T-- > 0) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int ans = INT32_MIN;

        for(int i=0; i<n; i++) {
            int sum = arr[i];
            ans = max(ans, sum);
            for(int j=i+1; j<n; j++) {
                sum += arr[j];
                ans = max(ans, sum);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
