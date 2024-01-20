#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
ll n;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cout <<'#'<<tc<<' ';
        cin >> n;

        ll lft = -1, rht = 2'000'000'000;
        ll mid;

        while(lft + 1 < rht) {
            mid = (lft + rht) / 2;

            ll expected = (mid * (mid+1)) / 2;

            if(expected <= n)
                lft = mid;
            else if(expected > n)
                rht = mid;
        }


        if(lft * (lft+1) / 2 == n) cout << lft << '\n';
        else cout << -1 << '\n';

    }
}