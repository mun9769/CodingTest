#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;
using ll = long long;
ll mod = 1'000'000'007;

int t;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t-- > 0) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        string ans;
        ans.push_back('1');
        for(int i=0; i<n-2; i++) {
            ans.push_back('2');
        }
        ans.push_back('1');
        cout << ans << '\n';
    }

    return 0;
}
